#include<iostream>
using namespace std;

int main()
{
	int T, i, a, b, ans1, ans2;
	cin>>T;
	while(T--) {
		cin>>a>>b;
		if((b-2*a)&1 || (b-2*a)<0) printf("No answer\n");
		else {
			ans2 = (b-2*a)/2;
			ans1 = a-ans2;
			if(ans1<0) {
				printf("No answer\n");
				continue;
			}
			cout<<ans1<<" "<<ans2<<endl;
		}
	}
	return 0;
}
