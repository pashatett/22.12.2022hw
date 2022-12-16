#include "Array.h"

template <class T>
Array<T>::Array() {
	for (int i{ 0 }; i < size; i++) {
		arr[i] = T();
	}
}

template <class T>
int Array<T>::getsize()const {
	return size;
}

template <class T>
T Array<T>::getItem(size_t index)const {
	if (index >= 0 && index < size) {
		return arr[index];
	}
	else
		cout << "Error";
}

template <class T>
void Array<T>::setItem(size_t index, T value) {
	if (index >= 0 && index < size) {
		arr[index] = value;
	}
	else
		cout << "Error";
}

template <class T>
void Array<T>::display() {
	for (int i{ 0 }; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

template <class T>
void Array<T>::sort() {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}