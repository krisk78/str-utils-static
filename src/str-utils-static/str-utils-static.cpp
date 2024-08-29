// str_utils.cpp : Defines the functions for the static library.
//

#include <cstdarg>
#include <sstream>

#ifdef _WIN32
#include <Windows.h>
#endif

#include <str-utils-static/str-utils-static.hpp>

std::string get_message(const char* fmt...)
// returns a string matching sprintf(buf, fmt...) - char * must be used for strings
{
    va_list args1;
    va_start(args1, fmt);
    va_list args2;
    va_copy(args2, args1);
    std::vector<char> msg(static_cast<size_t>(std::vsnprintf(nullptr, 0, fmt, args1)) + 1);
    va_end(args1);
    std::vsnprintf(msg.data(), msg.size(), fmt, args2);
    va_end(args2);
    std::string mesg(msg.begin(), msg.end());
    return mesg;
}

std::string to_lower(const std::string& str)
// converts str to lower case
{
    std::string s{ str };
    std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c) { return std::tolower(c); });
    return s;
}

std::string to_upper(const std::string& str)
// converts str to upper case
{
    std::string s{ str };
    std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c) { return std::toupper(c); });
    return s;
}

#ifdef _WIN32
std::wstring str_to_wstr(const std::string& str, unsigned int codepage)
{
    if (str.empty())
        return std::wstring();
    int len = MultiByteToWideChar(codepage, 0, &str[0], (int)str.size(), 0, 0);
    std::wstring result(len, 0);
    MultiByteToWideChar(codepage, 0, &str[0], (int)str.size(), &result[0], len);
    return result;
}
#endif // _WIN32

std::vector<std::string> split(const std::string& s, const char delim)
{
    std::vector<std::string> result;
    std::istringstream iss(s);
    std::string item;
    while (std::getline(iss, item, delim))
        result.push_back(item);
    return result;
}
