#pragma once

#include <iostream>
#include <algorithm>
#include <assert.h>

namespace shr
{
	class string
	{
	private:
		size_t _size;
		size_t _capacity;
		char* _str;

	public:
		typedef char* iterator;
		typedef const char* const_iterator;
		typedef char* reverse_iterator;
		typedef const char* const_reverse_iterator;

		static const size_t npos;

	public:
		////����&����
		string(const char* str = "")
			:_size(strlen(str)),
			_capacity(_size),
			_str(new char[_size + 1]) //+1��Ϊ�˸�'\0'Ԥ���ռ�
		{
			strcpy(_str, str);
		}

		//��ͳд��
		string(const string& s)
		{
			_str = new char[s._capacity + 1];
			memcpy(_str, s._str, s._size + 1); //_size + 1��Ϊ'\0'Ԥ���ռ�
			_size = s._size;
			_capacity = s._capacity;
		}

		//�ִ�д��
		//д��ʼ���б���ֹ��this��������������swapʱ��������
		//string(const string& s)
		//	:_size(s._size),
		//	_capacity(s._capacity),
		//	_str(nullptr)
		//{
		//	string tmp(s._str);
		//	swap(tmp);
		//}

		~string()
		{
			delete[] _str;
			_str = nullptr;
			_size = _capacity = 0;
		}

		////access
		const char* c_str() const
		{
			return _str;
		}

		char& operator[](size_t pos)
		{
			assert(pos < _size);
			return _str[pos];
		}

		const char& operator[](size_t pos) const
		{
			assert(pos < _size);
			return _str[pos];
		}

		size_t size() const
		{
			return _size;
		}

		////������
		iterator begin()
		{
			return _str;
		}

		iterator end()
		{
			return _str + _size;
		}

		const_iterator cbegin() const
		{
			return _str;
		}

		const_iterator cend() const
		{
			return _str + _size;
		}

		reverse_iterator rbegin()
		{
			return _str + _size;
		}

		reverse_iterator rend()
		{
			return _str;
		}

		const_reverse_iterator crbegin() const
		{
			return _str + _size;
		}

		const_reverse_iterator crend() const
		{
			return _str;
		}

		//��ɾ���
		void reserve(size_t n)
		{
			if (n > _capacity)
			{
				char* tmp = new char[n + 1]; //Ϊ'\0'�࿪һ���ֽڿռ�
				memcpy(tmp, _str, n + 1);
				delete[] _str;
				_str = tmp;
				_capacity = n;
			}
		}

		void push_back(char ch)
		{
			if (_size == _capacity) {
				reserve(_capacity == 0 ? 4 : _size * 2); //push֮ǰ�п����ǿմ���_capacityΪ0,
			}
			_str[_size++] = ch;
			_str[_size] = '\0'; //ĩβ��'\0'
		}

		void append(const char* str)
		{
			int len = strlen(str);
			if (_size + len > _capacity) {
				reserve(_size + len);
			}
			strcpy(_str + _size, str);
			_size += len;
		}

		string& operator+=(char ch)
		{
			push_back(ch);
			return *this;
		}

		string& operator+=(const char* str)
		{
			append(str);
			return *this;
		}

		string& insert(size_t pos, size_t n, char ch)
		{
			assert(pos < _size);
			if (_size + n > _capacity) {
				reserve(_size + n);
			}

			size_t end = _size;
			while (end >= pos && end != npos)
			{
				_str[end + n] = _str[end];
				--end;
			}

			for (int i = 0; i < n; ++i) {
				_str[pos + i] = ch;
			}
			_size += n; //ע�ⲻҪ���ǵ���_size

			return *this;
		}

		string& insert(size_t pos, const char* str)
		{
			assert(pos < _size);
			int len = strlen(str);
			if (_size + len > _capacity) {
				reserve(_size + len);
			}

			size_t end = _size;
			while (end >= pos && end != npos)
			{
				_str[end + len] = _str[end];
				--end;
			}

			for (int i = 0; i < len; ++i) {
				_str[pos + i] = str[i];
			}

			_size += len;

			return *this;
		}

		void erase(size_t pos = 0, size_t len = npos)
		{
			assert(pos < _size);
			if (len == npos || pos + len >= _size) {
				_str[pos] = '\0';
			}
			else
			{
				size_t end = pos + len;
				while (end <= _size) {
					_str[pos++] = _str[end++];
				}
			}
			//ע�ⲻ��ֱ��_size -= len,len ������npos
			_size = pos;
		}

		size_t find(char ch, size_t pos = 0)
		{
			assert(pos < _size);
			for (int i = pos; i < _size; ++i)
			{
				if (_str[i] == ch) {
					return i;
				}
			}
			return npos;
		}

		size_t find(const char* str, size_t pos = 0)
		{
			assert(pos < _size);
			char* ret = strstr(_str, str);
			if (ret) {
				return ret - _str;
			}
			else {
				return npos;
			}
		}

		string substr(size_t pos = 0, size_t len = npos)
		{
			assert(pos < _size);
			string tmp;
			if (len == npos || len + pos > _size)
			{
				for (int i = pos; i < _size; ++i) {
					tmp += _str[i];
				}
			}
			else
			{
				for (int i = pos; i < pos + len; ++i) {
					tmp += _str[i];
				}
			}
			return tmp;
		}

		void resize(size_t n, char ch = '\0')
		{
			if(n <= _size) {
				_str[_size] = '\0';
			}
			else
			{
				reserve(n);
				for (int i = _size; i < n; ++i) {
					_str[i] = ch;
				}
				_str[n] = '\0';
			}
			_size = n;
		}

		void swap(string& s)
		{
			std::swap(_str, s._str);
			std::swap(_size, s._size);
			std::swap(_capacity, s._capacity);
		}

		void clear()
		{
			if (_size != 0) {
				erase();
			}
		}

		bool empty()
		{
			return _size == 0;
		}

		////�Ƚ�
		//��ͳд��
		//string& operator=(const string& s)
		//{
		//	reserve(s._capacity);
		//	memcpy(_str, s._str, s._size + 1);
		//	_size = s._size;
		//	return *this;
		//}

		string& operator=(string tmp)
		{
			swap(tmp);
			return *this;
		}

		bool operator>(const string& s)
		{
			//hello helloxxx  true
			//helloxxx hello  false
			//hello hello  false
			int ret = memcmp(_str, s._str, _size < s._size ? _size : s._size);
			return ret == 0 ? _size > s._size : ret > 0;
		}

		bool operator==(const string& s)
		{
			return _size == s._size && memcmp(_str, s._str, _size) == 0;
		}

		bool operator!=(const string& s)
		{
			return !(*this == s);
		}

		bool operator>=(const string& s)
		{
			return (*this > s || *this == s);
		}

		bool operator<(const string& s)
		{
			return !(*this >= s);
		}

		bool operator<=(const string& s)
		{
			return !(*this > s);
		}
	};

	const size_t string::npos = -1;
}

////�������
std::ostream& operator<<(std::ostream& cout, const shr::string& s)
{
	for (int i = 0; i < s.size(); ++i) {
		cout << s[i];
	}
	return cout;
}

std::istream& operator>>(std::istream& cin, shr::string& s)
{
	s.clear(); //clearʵ�����ݸ���

	//get���Զ�ȡ�����ַ�
	char ch = cin.get();
	//��ջ������е�ǰ�ÿո�ͻ���
	while (ch == ' ' || ch == '\n') {
		ch = cin.get();
	}

	//�ֽ�������ַ�����buff�У�buff�����ٷ��������
	//�������ݴ���
	char buff[128];
	int i = 0;
	while (ch != ' ' && ch != '\n')
	{
		buff[i++] = ch;
		buff[i] = '\0';
		if (i == 127)
		{
			s += buff;
			i = 0;
		}
		ch = cin.get();
	}
	if (i != 0) {
		s += buff;
		i = 0;
	}
	return cin;
}