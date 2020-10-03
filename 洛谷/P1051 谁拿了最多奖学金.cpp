#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

int main()
{
	int i, N, ans=0, Tmax=0, add, qimo, ping, lunwen;
	char ganbu, xibu;
	string fir, now;
	cin>>N;
	for(i=1;i<=N;i++) {
		cin>>now;
		scanf("%d %d %c %c %d", &qimo, &ping, &ganbu, &xibu, &lunwen);
		add = 0;
		if(qimo>80 && lunwen>=1) add+=8000;
		if(qimo>85 && ping>80) add+=4000;
		if(qimo>90) add+=2000;
		if(qimo>85 && xibu=='Y') add+=1000;
		if(ping>80 && ganbu=='Y') add+=850;
		if(add>Tmax) {
			Tmax = add;
			fir = now;
		}
		ans += add;
	}
	cout<<fir<<endl<<Tmax<<endl<<ans;
	return 0;
}
