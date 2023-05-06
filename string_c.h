//   _________     ___.            /\                    __         .__                 
//  /   _____/ ____\_ |__   ____   )/______      _______/  |________|__| ____    ____   
//  \_____  \_/ __ \| __ \ /  _ \   /  ___/     /  ___/\   __\_  __ \  |/    \  / ___\  
//  /        \  ___/| \_\ (  <_> )  \___ \      \___ \  |  |  |  | \/  |   |  \/ /_/  > 
// /_______  /\___  >___  /\____/  /____  >    /____  > |__|  |__|  |__|___|  /\___  /  
//         \/     \/    \/              \/          \/                      \//_____/   
//                 2023         All rights reserved to Sebastian R.						



#pragma once
#include <memory>
#include <stdlib.h>
#include <ostream>

class _string {
public:
	char* m_string;
	_string(const char* string)
	{
		if (string == nullptr) {
			m_string = new char[1];
			m_string[0] = '\0';
		}
		else {
			unsigned int size = strlen(string);
			m_string = new char[size + 1];
			strncpy_s(m_string, size + 1, string, size);
			m_string[size] = '\0';
		}
	}
	_string(const _string& str) {				// copy constructor
		int str_size = strlen(str.m_string);
		m_string = new char[str_size + 1];
		strncpy_s(m_string, str_size + 1, str.m_string, str_size);
		m_string[str_size] = '\0';
	}
	_string()
		:m_string{ nullptr }
	{
		m_string = new char[1];
		m_string[0] = '\0';
	}
	~_string() {
		delete[] m_string;
	}
public:
	int _length() {
		if (m_string != nullptr) {
			return strlen(m_string);
		}
		return 0;
	}
	int _find(_string& word) {
		int index = 0;
		for (int i = 0; i < _length(); i++)
		{
			while (m_string[i + index] == word.m_string[index] && word.m_string[index] != 0)
			{
				++index;
			}
			if (index == word._length())
			{
				return i; //return starting index
			}
		}
		return -1;
	}
	int _find(_string& word, unsigned short _start) {
		int index = 0;
		for (unsigned int i = _start; i < _length(); i++)
		{
			while (m_string[i + index] == word.m_string[index] && word.m_string[index] != 0)
			{
				++index;
			}
			if (index == word._length())
			{
				return i; //return starting index
			}
		}
		return -1;
	}
	int _find(char _start_f, _string& word, char _end_f) {
		int index = 0;
		for (unsigned int i = 0; i < _length(); i++)
		{
			while (m_string[i + index] == word.m_string[index] && word.m_string[index] != 0)
			{
				++index;
			}
			if (index == word._length() && m_string[i - 1] == 0)
			{
				return i;
			}
			if (index == word._length() && m_string[i - 1] == _start_f && m_string[i + word._length()] == _end_f) {
				return i;
			}
		}
		return -1;
	}
	int _find(char _start_f, _string& word, char _end_f, short _start) {
		int index = 0;
		for (unsigned int i = _start; i < _length(); i++)
		{
			while (m_string[i + index] == word.m_string[index] && word.m_string[index] != 0)
			{
				++index;
			}
			if (index == word._length() && m_string[i - 1] == 0)
			{
				return i;
			}
			if (index == word._length() && m_string[i - 1] == _start_f && m_string[i + word._length()] == _end_f) {
				return i;
			}
		}
		return -1;
	} //filter find
	int _toint(int _Base = 10) {
		const char* _Ptr = m_string;
		char* _Eptr;
		const long _Ans = strtol(_Ptr, &_Eptr, _Base);
		if (_Ptr == _Eptr) {
			return -1; //check if it is a valid number
		}
		return _Ans;
	}
	_string& operator=(char c_char) {
		if (m_string[0] == c_char)
		{
			return *this;
		}
		delete[] m_string;
		m_string = new char[2];
		m_string[0] = c_char;
		m_string[1] = '\0';
		return *this;
	}
	_string& operator=(_string& other_string) {
		if (this == &other_string)
		{
			return *this;
		}
		delete[] m_string;
		m_string = new char[strlen(other_string.m_string) + 1];
		strncpy_s(m_string, strlen(other_string.m_string) + 1, other_string.m_string, strlen(other_string.m_string));
		return *this;
	}
	_string& operator=(const char* c_char_ptr)
	{
		delete[] m_string;
		m_string = new char[strlen(c_char_ptr) + 1];
		strncpy_s(m_string, strlen(c_char_ptr) + 1, c_char_ptr, strlen(c_char_ptr));
		return *this;
	}
	void operator+=(_string& other_string) {
		int st_size = other_string._length() + this->_length() + 1;
		char* temp_strn = new char[st_size];
		strncpy_s(temp_strn, st_size, m_string, _length());
		strncat_s(temp_strn, st_size, other_string.m_string, other_string._length());
		delete[] m_string;
		m_string = new char[st_size + 1];
		strncpy_s(m_string, st_size + 1, temp_strn, st_size);
		m_string[st_size] = '\0';
		delete[] temp_strn;
	}
	void operator+=(char a) {
		int st_size = _length() + 1;
		char* temp_strn = new char[st_size + 1];
		strncpy_s(temp_strn, st_size + 1, m_string, _length());
		strncat_s(temp_strn, st_size + 1, &a, _TRUNCATE);
		temp_strn[st_size] = '\0';
		delete[] m_string;
		m_string = new char[st_size + 1];
		strncpy_s(m_string, st_size + 1, temp_strn, st_size);
		m_string[st_size] = '\0';
		delete[] temp_strn;
	}
	void operator+(_string& other_string) {
		int total_str_size = other_string._length() + _length();
		char* new_gen_char = new char[total_str_size + 1];
		strncpy_s(new_gen_char, total_str_size + 1, m_string, _length());
		strncat_s(new_gen_char, total_str_size + 1, other_string.m_string, other_string._length());
		new_gen_char[total_str_size] = '\0';
		strncpy_s(m_string, total_str_size + 1, new_gen_char, total_str_size);
		delete[] new_gen_char;
	}
	friend std::ostream& operator<<(std::ostream& os, _string& other_string)
	{
		os << other_string.m_string;
		return os;
	}
};
