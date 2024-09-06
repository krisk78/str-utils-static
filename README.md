# str-utils-static static library

This library provides functions:

## Format

### std::string get_message(const char* format, values...)
Format a string in sprintf style

## Conversions

### std::string to_lower(const std::string& str)
Returns the passed string in lowercase

### std::string to_upper(const std::string& str)
Returns the passed string in uppercase

### std::wstring str_to_wstr(const std::string& str, unsigned int codepage)
Returns the passed string converted in utf-16 using the given codepage
Only available for Windows targets

## Remove extra spaces

### void ltrim(std::string& str)
Removes the spaces at the left of the string

### void rtrim(std::string& str)
Removes the spaces at the right of the string

### void trim(std::string& str)
Removes the spaces at both left and right of the string

### std::string ltrimc(std::string str)
Same as ltrim but leaving the passed string unchanged

### std::string rtrimc(std::string str)
Same as rtrim but leaving the passed string unchanged

### str::string trimc(std::string str)
Same as trim but leaving the passed string unchanged

## Split

### std::vector<std::string> split(const std::string& str, const char delim)
Cuts the given string using the delimitation char and returns a vector containing each part
