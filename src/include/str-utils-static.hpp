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

/*! \brief Returns a string matching sprintf(buf, fmt...) - c-string type (char *) must be used for strings.
	\param fmt...	list of parameters in the sprintf style: the 1st is the format string and nexts are the variables to print as specified by the format string.
	\sa Refer to <a href="https://en.cppreference.com/w/cpp/io/c/fprintf" target="_blank">cppreference.com</a> for details.
*/
std::string get_message(const char* fmt...);

/*!	\brief Converts str to lower case
*/
std::string to_lower(const std::string& str);

/*!	\brief Converts str to upper case
*/
std::string to_upper(const std::string& str);

#ifdef _WIN32
/*!	\brief Converts a string to utf-16 wide string using the specified codepage.
	\warning This function is only implemented for Windows platforms.
	\param codepage This function uses the function MultiByteToWideChar.
	\sa Refer to <a href="https://docs.microsoft.com/en-us/windows/win32/api/stringapiset/nf-stringapiset-multibytetowidechar" target="_blank">MultiByteToWideChar function (stringapiset.h)</a> (Microsoft)
	for details on codepage identifiers.

	Note that the result string must be converted to a c-string with std::string::c_str() to get a LPCWSTR string.
*/
std::wstring str_to_wstr(const std::string& str, unsigned int codepage);
#endif // _WIN32

/*! \brief Deletes in place the spaces present at the left of the given string. */
static inline void ltrim(std::string& s)
{
	s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) { return !std::isspace(ch); }));
}

/*! \brief Deletes in place the spaces present at the right of the given string. */
static inline void rtrim(std::string& s)
{
	s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) { return !std::isspace(ch); }).base(), s.end());
}

/*! \brief Deletes in place the spaces present at both left and right of the given string. */
static inline void trim(std::string& s)
{
	ltrim(s);
	rtrim(s);
}

/*! \brief Returns a string without left spaces. */
static inline std::string ltrimc(std::string s)
{
	ltrim(s);
	return s;
}

/*! \brief Returns a string without right spaces. */
static inline std::string rtrimc(std::string s)
{
	rtrim(s);
	return s;
}

/*! \brief Returns a string without both left and right spaces. */
static inline std::string trimc(std::string s)
{
	trim(s);
	return s;
}

/*! \brief Returns the list of elements of the given string delimited by the given char. */
std::vector<std::string> split(const std::string& s, const char delim);

