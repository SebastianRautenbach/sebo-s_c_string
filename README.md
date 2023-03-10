# c_string
A simpler, more effective and faster version of std::string
This header can be used in all projects and can be modified to your liking.
This header was created just to ease future projects for myself and others.

FUNCTIONS:
_find() has a few variants, _find(word) is used to find a set of char's in a array/char* it returns the starting position where it is found
_find(word, last index) is used to find the position of the char's at any given starting index.
_find(begin match, word, end match) is used to find a specific char position that might be obstructed between other char’s. For example trying to find “is” in “this is” will return an index of 2 which is incorrect, the std string library does not have much support so you are forced to use regex find but it does not return a position but a bool which is not helpful.
_find(begin match, word, end match, last index) is the same as the above mentioned function but can start at any index.
_toint() returns the string in numbers but wont return if it’s not a number.
_length returns the length of characters inside the array.
