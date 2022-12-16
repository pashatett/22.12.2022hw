#pragma once
#include <iostream>
using namespace std;

class Date {
	int day;
	int month;
	int year;

public:
	Date(int d, int m, int y) : day{ d }, month{ m }, year{ y }{}
	Date() :Date(0, 0, 0) {}

	int operator-=(Date& date) {
		return abs(abs(dif(month) - dif(date.month)) + (year - date.year) * 365);
	}

	int dif(int m) {
		int sumDay = 0;
		for (int i{ 1 }; i < m; i++) {
			switch (i) {
			case 1:
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			case 12:
				sumDay += 31;
				break;
			case 4:
			case 6:
			case 9:
			case 11:
				sumDay += 30;
				break;
			case 2:
				sumDay += 28;
				break;
			default:
				break;
			}
		}
		return sumDay + day;
	}

	Date operator+=(int d) {
		day += d;
	}

	int ssum(int d) {
		int y = d / 365;
		int dd = d % 365;
		int m = 0;
		while (dd > 0) {
			for (int i{ 1 }; i <= 12; i++) {
				switch (i) {
				case 1:
				case 3:
				case 5:
				case 7:
				case 8:
				case 10:
				case 12:
					dd -= 31;
					m += 1;
					break;
				case 4:
				case 6:
				case 9:
				case 11:
					dd -= 30;
					m += 1;
					break;
				case 2:
					dd -= 28;
					m += 1;
					break;
				default:
					break;
				}
			}
		}
	}

	void operator++() {
		day++;
	}
	void operator--() {
		day--;
	}
	bool operator!=(Date& a) {
		if (a.day != day && a.month != month && a.year != year)return true;
		else return false;
	}
	bool operator==(Date& a) {
		if (a.day == day && a.month == month && a.year == year)return true;
		else return false;
	}
	bool operator>(Date& a) {
		if (a.year>year || (a.month>month && a.year==year) 
			|| (a.day>day && a.month == month && a.year == year))
			return true;
		else return false;
	}
	bool operator<(Date& a) {
		if (a.year < year || (a.month < month && a.year == year)
			|| (a.day < day && a.month == month && a.year == year))
			return true;
		else return false;
	}
	void operator=(Date a) {
		day = a.day;
		month = a.month;
		year = a.year;
	}
};
