#include<iostream>
#include<cstring>
#define Max(a,b) (a>b?a:b)
using namespace std;
int A[35], V[35];  //����͵��ڼ�ֵ
const int MAXN = 2e4+10;
int dp[MAXN];  //���װ�µ���Ʒ��ֵ 

int main()
{
	memset(dp, 0, sizeof(dp));
	int M, N, i, j;  //M�ݻ� 
	cin>>M>>N;
	for(i=1;i<=N;i++) cin>>A[i], V[i]=A[i];
	for(i=1;i<=N;i++) {
		for(j=M;j>=V[i];j--) dp[j] = Max(dp[j], dp[j-V[i]]+A[i]);
	}
	cout<<M-dp[M];
	return 0;
}
