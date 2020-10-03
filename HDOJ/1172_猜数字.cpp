#include<iostream>
#include<cstdio>
#include<cstring>
#define Min(a,b) (a<b?a:b) 
using namespace std;
const int MAXN = 105;
int N;  //N�ζԻ� 
int num[MAXN], A[MAXN], B[MAXN];  //�����A������ B����������ȷ��λ���� 

inline bool fun(int a) {  //�ж�a�Ƿ�������� 
	bool flag = true;
	for(int i=1;i<=N;i++) {
		//�����ж�λ�õ���ȷ��
		int cnt = 0;
		if(a%10 == num[i]%10) cnt++;
		if((a/10)%10 == (num[i]/10)%10) cnt++;
		if((a/100)%10 == (num[i]/100)%10) cnt++;
		if(a/1000 == num[i]/1000) cnt++;
		if(cnt != B[i]) {  //���������� 
			flag = 0;
			break;
		}
		//�ж���������ȷ��
		int T1[10]={0}, T2[10]={0}, cnt2 = 0;
		T1[a%10]++; T1[(a/10)%10]++; T1[(a/100)%10]++; T1[a/1000]++; 
		T2[num[i]%10]++; T2[(num[i]/10)%10]++; T2[(num[i]/100)%10]++; T2[num[i]/1000]++; 
		for(int j=0;j<10;j++) cnt2 += Min(T1[j], T2[j]);
		if(cnt2 != A[i]) {  //���������� 
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
