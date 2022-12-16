#pragma once
#include <iostream>
using namespace std;

class String {
	char* str;
	int siz = 80;
public:
	String() {
		str = new char[siz];
	}
	String(int size) {
		str = new char[size];
	}
	String(const char* user_str) {
		str = new char[strlen(user_str)];
		strcpy_s(str, strlen(user_str) + 1, user_str);
	}
	void setstr() {
		char* temp = new char[80];
		cin.getline(temp, 80);
		strcpy_s(str, 81, temp);
		delete[]temp;
	}
	char* getstr() {
		return str;
	}



	String(String&& st):str { nullptr } {
		str = st.str;

		st.str = nullptr;
	}

	char operator[](int index) {
		return str[index];
	}

	int operator()(char a) {
		for (int i{ 0 }; i < siz; i++) {
			if (str[i] == a) {
				return i;
			}
			else return -1;
		}
	}
};
