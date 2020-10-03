#include<iostream>
#include<string>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
int N, len, ans[30], chose[30], cur=0;  //N进制, len算式长度 
int A[40], B[40], C[40];
bool use[30], flag=false;

void print() {
	for(int i=0;i<len;i++) {
		printf("%d%c", ans[i], i==len-1?'\n':' ');
	}
	flag=true;exit(0);
}

bool ok() {
	int up = 0;
	for(int i=len-1;i>=0;i--) {
		int a = ans[A[i]];
		int b = ans[B[i]];
		int c = ans[C[i]];
		if((a+b+up)%N != c) return false;
		up = (a+b+up)/N;
	}
	return true;
}

void dfs(int step) { 
	if(flag) return;
	if(step>=N && ok()) print();  //判断 
	if(ans[A[0]-'0'] + ans[B[0]-'0']>=N) return;  //第一位不能进位  剪枝1 
	int i, j, up;
	for(i=len-1;i>=0;i--) {  // 剪枝2
		int a = ans[A[i]];
		int b = ans[B[i]];
		int c = ans[C[i]];
		if(a>=0 && b>=0 && c>=0) {
			if((a+b)%N!=c && (a+b+1)%N!=c) return;
		}
	}
	for(i=N-1;i>=0;i--) {
		if(!use[i]) {
			use[i] =  true;
			ans[chose[step]] = i;
			dfs(step+1);
			ans[chose[step]] = -1;
			use[i] = false;
		}
	}
}

void fun(int now) {
	if(!use[now]) {
		use[now] = true;
		chose[cur++] = now;
	}
}

int main()
{
	memset(ans, -1, sizeof(ans));
	cin>>N;
	string s1, s2, s3;
	cin>>s1>>s2>>s3;
	len = s1.length();
	for(int i=len-1;i>=0;i--) {
		A[i]=s1[i]-'A', B[i]=s2[i]-'A', C[i]=s3[i]-'A';
		fun(A[i]), fun(B[i]), fun(C[i]);
	}
	//for(int i=0;i<len;i++) cout<<chose[i];
	memset(use, false, sizeof(use));
	dfs(0);
	return 0;
}
