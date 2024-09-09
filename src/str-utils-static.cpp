// \file str-utils-static.cpp
// \brief implements the non-inline functions of the static library.
//

#include <cstdarg>
#include <sstream>

#ifdef _WIN32
#include <Windows.h>
#endif

#include <str-utils-static.hpp>

std::string str_utils::get_message(const char* fmt...)
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

#ifdef _WIN32
std::wstring str_utils::str_to_wstr(const std::string& str, unsigned int codepage)
{
    if (str.empty())
        return std::wstring();
    int len = MultiByteToWideChar(codepage, 0, &str[0], (int)str.size(), 0, 0);
    std::wstring result(len, 0);
    MultiByteToWideChar(codepage, 0, &str[0], (int)str.size(), &result[0], len);
    return result;
}
#endif // _WIN32

std::vector<std::string> str_utils::split(const std::string& s, const char delim)
{
    std::vector<std::string> result;
    std::istringstream iss(s);
    std::string item;
    while (std::getline(iss, item, delim))
        result.push_back(item);
    return result;
}
