#include<iostream>
#include<cstdio>
#include<string> 
using namespace std;

int main()
{
	int cnt=1, i, ans=0, len, num;
	string s;
	while(1) {
		num=0, ans=0;
		cin>>s;
		if(s[0]=='-') break;
		len = s.length();
		printf("%d. ", cnt++);
		for(i=0;i<len;i++) {
			if(s[i]=='}') { 
				if(num<=0) {  //°Ñ}¸ÄÎª{
					num=1;
					ans++;
				}
				else num--;
			}
			else num++;
		}
		ans += num/2;
		printf("%d\n", ans);
	}
	return 0;
}
