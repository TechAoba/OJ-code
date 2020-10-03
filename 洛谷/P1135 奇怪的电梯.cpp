#include<iostream>
using namespace std;
int N, A, B;
int K[205], cnt[205];

int main()
{
	cin>>N>>A>>B;
	if(A==B) {
		cout<<0; return 0;
	}
	int i, j, step=1;
	cnt[A] = 1;
	for(i=1;i<=N;i++) cin>>K[i];
	while(true) {
		step++;
		bool find = false;
		for(j=1;j<=N;j++) {
			if(cnt[j]==step-1) {
				int t1 = j + K[j];
				int t2 = j - K[j];
				if(t1==B || t2==B) {
					cout<<step-1; return 0;
				}
				if(t1>=1 && !cnt[t1]) {
					find = true;
					cnt[t1] = step;
				}
				if(t2>=1 && !cnt[t2]) {
					find = true;
					cnt[t2] = step;
				}
			}
		}
		if(!find) break;
	}
	cout<<-1;
	return 0;
}
