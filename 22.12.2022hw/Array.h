#pragma once
#include <iostream>
using namespace std;

template <class T>
class Array {
	static const size_t size{ 5 };
	T arr[size];

public:
	Array();
	int getsize()const;
	T getItem(size_t index)const;
	void setItem(size_t index, T value);
	void display();
	void sort();

	Array(Array&& arr) : arr{ nullptr }
	{
		arr = p.arr;

		p.arr = nullptr;
	}
};