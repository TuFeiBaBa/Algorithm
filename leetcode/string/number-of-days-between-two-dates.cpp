#include <string>
#include <vector>

using namespace std;
/*
* 日期之间隔几天 https://leetcode.cn/problems/number-of-days-between-two-dates/description/
*/
class Solution {
private:
	vector<int> months = { 31,28,31,30,31,30,31,31,30,31,30,31 };

	bool isLeapYear(int year) {
		return year % 400 == 0 || year % 4 == 0 && year % 100 != 0;
	}

	int getDays(vector<int>& date) {
		int year = date[0];
		int month = date[1];
		int day = date[2];
		int days = 0;
		for (int i = 0; i < month - 1; i++) {
			if (i == 1) {
				if (isLeapYear(year)) days++;
			}
			days += months[i];
		}
		return days + day;
	}

public:
	int daysBetweenDates(string date1, string date2) {
		//"2019-06-29"
		vector<int> d1 = {
			 stoi(date1.substr(0,4)),
			 stoi(date1.substr(5,2)),
			 stoi(date1.substr(8,2))
		};
		vector<int> d2 = {
			stoi(date2.substr(0,4)),
			stoi(date2.substr(5,2)),
			stoi(date2.substr(8,2))
		};

		if (d2[0] > d1[0] || 
			d2[0] == d1[0] && d2[1] > d1[1] || 
			d2[0] == d1[0] && d2[1] == d1[1] && d2[2] > d1[2]) {
			vector<int> tmp = d1;
			d1 = d2;
			d2 = tmp;
		}

		if (d1[0] == d2[0]) {
			return getDays(d1) - getDays(d2);
		}
		else {
			int days = 0;
			vector<int> d(3);
			for (int i = 1; i < d1[0] - d2[0]; i++) {
				d[0] = d2[0] + i;
				d[1] = 12;
				d[2] = 31;
				days += getDays(d);
			}

			return getDays(d1) + days + isLeapYear(d2[0]) ? 366 - getDays(d2) : 365 - getDays(d2);
		}
	}
};
int main() {

}