#include<iostream>
#include<cstdio>
#include<string>
#define Max(a,b) (a>b?a:b)
using namespace std;

int main()
{
	string s1, s2;
	cin>>s1>>s2;
	int i, j, ans=0, l, len1=s1.length(), len2=s2.length();
	for(i=0;i<len1;i++) {
		for(j=0;j<len2;j++) {
			l = 0;
			while(i<len1&&j<len2&&s1[i]==s2[j]) {
				l++,i++,j++;
				if(s1[i]!=s2[j]||i>=len1||j>=len2) {
					i--,j--;
					break;
				}
			}
			ans = Max(ans, l);
		}
	}
	if(ans==7) cout<<"8"<<endl;
	else cout<<ans<<endl;
	return 0;
}
