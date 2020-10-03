#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int monthDay[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int T;

bool is_run(int year) {
	if(year%400==0 || year%4==0 && year%100!=0) return true;
	return false;
}

int main()
{
	scanf("%d", &T);
	int i, year, month, day;
	int tar1, tar2, tar3;
	for(i=1;i<=T;i++) {
		scanf("%d-%d-%d", &year,&month,&day);
		int shang = monthDay[month];
		if(month==2 && is_run(year)) shang++;  //日的上线 
		tar1 = year+18;
		tar2 = month;
		tar3 = day;
		if(day==29) printf("-1\n");
		else {
			int ans = 0;
			while(year!=tar1 || month!=tar2 || day!=tar3) {
				ans++;
				day++;
				if(day>shang) {
					day = 1;
					month++;
					if(month>12) {
						month=1;
						year++;
					}
					shang = monthDay[month];
					if(month==2 && is_run(year)) shang++;  //日的上线 
				}
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}
