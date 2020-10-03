#include<iostream>
#include<cctype>
#include<cstdio>
#define LL long long
using namespace std;
const int maxn = 5e5+10;
int A[maxn], B[maxn], N;
LL ans = 0;

inline int get() {
	int flag = 1, val = 0;
	char ch = getchar();
	while(!isdigit(ch)) {
		if(ch == '-') flag = -1;
		ch = getchar();
	} 
	while(isdigit(ch)) {
		val = (val<<1) + (val<<3) + (ch^48);
		ch = getchar();
	}
	return flag * val;
}

void merge(int l, int r) {
	if(l==r) return;
	int mid = l+r>>1;
	merge(l, mid); merge(mid+1, r);
	int i=l, j=mid+1, k=l;
	while(i<=mid && j<=r) {
		if(A[j]>=A[i]) {
			B[k++] = A[i++];
		}
		else {
			B[k++] = A[j++];
			ans += mid-i+1;
		}
	}
	while(i<=mid) B[k++] = A[i++];
	while(j<=r) B[k++] = A[j++];
	for(i=l;i<=r;i++) A[i] = B[i];
}

int main()
{
	int i;
	N = get();
	for(i=1;i<=N;i++) A[i] = get();
	merge(1, N);
	cout<<ans; 
	return 0;
}
