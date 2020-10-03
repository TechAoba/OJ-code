#include<iostream>
#include<string>
#include<cstdio>
#include<cstring>
using namespace std;
int ans[500]={1}, l = 1, A[10], B[10];
bool tran[10][10], vis[10];

int binaryPow(int a, int b) {
	int num=1;
	while(b) {
		if(b&1) num*=a;
		a*=a;
		b>>=1;
	}
	return num;
}

void mul(int a) {
	int i;
	for(i=0;i<l;i++) ans[i]*=a;
	for(i=0;i<l;i++) {
		ans[i+1] += ans[i]/10;
		ans[i] = ans[i]%10;
	}
	while(ans[l]) {
		ans[l+1] += ans[l]/10;
		ans[l] = ans[l]%10;
		l++;
	}
}

bool dfs(int a, int b) {
	if(tran[a][b]) return true;
	int i;
	for(i=0;i<10;i++) {
		if(!vis[i] && tran[a][i]) {
			vis[i] = true;
			if(dfs(i, b)) return true;
		}
	}
	return false;
}

int main()
{
	memset(B, 0, sizeof(B));
	string s;
	int i, j, k, a, b;
	cin>>s>>k;
	for(i=0;i<s.length();i++) B[s[i]^48]++;
	for(i=0;i<10;i++) A[i]=1;
	while(k--) {
		scanf("%d %d", &a, &b);
		if(a==b) continue;
		tran[a][b] = true;
	}
	
	for(i=0;i<10;i++) {
		for(j=0;j<10;j++) {
			if(i==j) continue;
			if(tran[i][j]) A[i]++;
			else {
				memset(vis, 0, sizeof(vis));
				A[i] += dfs(i, j); 
			}
		}
	}
	for(i=0;i<10;i++) {
		//cout<<i<<"  "<<A[i]<<"  "<<B[i]<<endl;
		mul(binaryPow(A[i], B[i]));
	}
	for(i=l-1;i>=0;i--) cout<<ans[i];
	return 0;
}
