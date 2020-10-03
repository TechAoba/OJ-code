#include<iostream>
#include<cstdio>
#include<cstring>
#define Min(a,b) (a<b?a:b) 
using namespace std;
const int MAXN = 105;
int N;  //N段对话 
int num[MAXN], A[MAXN], B[MAXN];  //答对了A个数字 B个数字在正确的位置上 

inline bool fun(int a) {  //判断a是否符合条件 
	bool flag = true;
	for(int i=1;i<=N;i++) {
		//首先判断位置的正确性
		int cnt = 0;
		if(a%10 == num[i]%10) cnt++;
		if((a/10)%10 == (num[i]/10)%10) cnt++;
		if((a/100)%10 == (num[i]/100)%10) cnt++;
		if(a/1000 == num[i]/1000) cnt++;
		if(cnt != B[i]) {  //不符合条件 
			flag = 0;
			break;
		}
		//判断数量的正确性
		int T1[10]={0}, T2[10]={0}, cnt2 = 0;
		T1[a%10]++; T1[(a/10)%10]++; T1[(a/100)%10]++; T1[a/1000]++; 
		T2[num[i]%10]++; T2[(num[i]/10)%10]++; T2[(num[i]/100)%10]++; T2[num[i]/1000]++; 
		for(int j=0;j<10;j++) cnt2 += Min(T1[j], T2[j]);
		if(cnt2 != A[i]) {  //不符合条件 
			flag = 0;
			break;
		}
	}
	return flag;
}

int main()
{
	while(scanf("%d", &N)!=EOF) {
		if(N==0) break;
		int i, cnt = 0, ans=0;
		for(i=1;i<=N;i++) scanf("%d %d %d", &num[i], &A[i], &B[i]);
		for(i=1000;i<10000;i++) {
			if(fun(i)) ans = i, cnt++;
		}
		if(cnt==1) printf("%d\n", ans);
		else printf("Not sure\n");
	}
	return 0;
} 
