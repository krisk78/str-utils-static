#pragma once

/*! \file str-utils-static.hpp
*	\brief Few string functions. See functions documentation for details.
*	\author Christophe COUAILLET
*/

#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
#endif

#include <string>
#include <algorithm>
#include <vector>

/*! \namespace str_utils
	\brief Namespace of the library functions
*/
namespace str_utils
{

/*! \brief Returns a string matching sprintf(buf, fmt...) - c-string type (char *) must be used for strings.
	\param fmt	list of parameters in the sprintf style: the 1st is the format string and nexts are the variables to print as specified by the format string.
	\return a formatted string made up of the first agument as template, within following argument's values are substituted
	\sa Refer to <a href="https://en.cppreference.com/w/cpp/io/c/fprintf" target="_blank">cppreference.com</a> for details.
*/
std::string get_message(const char* fmt...);

/*!	\brief Converts str to lower case
*	\param str	string to convert to lowercases
*	\return a lowercase copy of the passed string str
*/
inline std::string to_lower(const std::string& str)
{
	std::string s{ str };
	std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c) { return std::tolower(c); });
	return s;
}

/*!	\brief Converts str to upper case
*	\param str	string to convert to uppercases
*	\return an uppercase copy of the passed string str
*/
inline std::string to_upper(const std::string& str)
{
	std::string s{ str };
	std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c) { return std::toupper(c); });
	return s;
}

#ifdef _WIN32
/*!	\brief Converts a string to utf-16 wide string using the specified codepage.
	\warning This function is only implemented for Windows platforms.
	\param str The string to convert
	\param codepage The codepage to use
	\return an utf-16 wide string equivalent to str
	\sa This function uses the function MultiByteToWideChar. Refer to <a href="https://docs.microsoft.com/en-us/windows/win32/api/stringapiset/nf-stringapiset-multibytetowidechar" target="_blank">MultiByteToWideChar function (stringapiset.h)</a> (Microsoft)
	for details on codepage identifiers.

	Note that the result string must be converted to a c-string with std::string::c_str() to get a LPCWSTR string.
*/
std::wstring str_to_wstr(const std::string& str, unsigned int codepage);
#endif // _WIN32

/*! \brief Deletes in place the spaces present at the left of the given string.
*	\param s	string from which left spaces must be removed
*/
inline void ltrim(std::string& s)
{
	s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) { return !std::isspace(ch); }));
}

/*! \brief Deletes in place the spaces present at the right of the given string.
*	\param s	string from which right spaces must be removed
*/
inline void rtrim(std::string& s)
{
	s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) { return !std::isspace(ch); }).base(), s.end());
}

/*! \brief Deletes in place the spaces present at both left and right of the given string.
*	\param s	string from which both left and rigth spaces must be removed
*/
inline void trim(std::string& s)
{
	ltrim(s);
	rtrim(s);
}

/*! \brief Returns a string without left spaces.
*	\param s	string from which left spaces must be removed
*	\return	a copy of the passed string s without left spaces
*/
inline std::string ltrimc(const std::string& s)
{
	std::string result{ s };
	ltrim(result);
	return result;
}

/*! \brief Returns a string without right spaces.
*	\param s	string from which right spaces must be removed
*	\return a copy of the passed string s without right spaces
*/
inline std::string rtrimc(const std::string& s)
{
	std::string result{ s };
	rtrim(result);
	return result;
}

/*! \brief Returns a string without both left and right spaces.
*	\param s	string from which both left and right spaces must be removed
*	\return	a copy of the passed string s without both left and right spaces
*/
inline std::string trimc(const std::string& s)
{
	std::string result{ s };
	trim(result);
	return result;
}

/*! \brief Returns the list of elements of the given string delimited by the given char.
*	\param s	string to split
*	\param delim	char used as delimiter
*	\return	a list including the splitted parts of the passed string s
*/
std::vector<std::string> split(const std::string& s, const char delim);

}
