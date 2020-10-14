#include<iostream>
#include<cstdio>
using namespace std;
int year=2020, month=1, day=22, hour=10, minute=2, sec=2, N;  //日期是两位相同 

bool fun(int year) {  //判断年逆置是否合理 
	int tm = (year%10)*10+(year%100)/10;
	if(tm>59) return false;
	int ts = ((year/100)%10)*10+year/1000;
	if(ts>59) return false;
	minute=tm, sec=ts;
	return true;
}

int main()
{
	cin>>N;
	bool ok = false;
	while(year<=9999) {
		if(!fun(year)) {
			year++;
			continue;
		}
		if((day==11||day==22) && (hour%10)*10+hour/10==month) N--;
		if(N<0) break;
		hour++;
		if(hour>23) hour=0, day++;  //过了一天 
		if(day<11) day=11;
		else if(day>11&&day<22) day=22;
		else if(day>22) day=11, month++;
		if(month>12) year++, month=1;
	}
	printf("%04d%02d%02d%02d%02d%02d\n", year, month, day, hour, minute, sec);
	return 0;
 } 
