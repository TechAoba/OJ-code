#include<iostream>
#define Max(a,b) (a>b?a:b)
using namespace std;
int dp[30010], v[30], w[30];

int main()
{
	int N, M, i, j, val;  //N����Ǯ��  M������Ʒ�ĸ���
	cin>>N>>M;
	for(i=1;i<=M;i++) {
		cin>>v[i]>>val;
		w[i] = v[i] * val;
	}
	for(i=1;i<=M;i++) {
		for(j=N;j>=v[i];j--) {
			dp[j] = Max(dp[j], dp[j-v[i]]+w[i]);
		}
	}
	cout<<dp[N];
	return 0;
}
