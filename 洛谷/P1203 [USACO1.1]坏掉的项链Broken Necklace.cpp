#include<iostream>
#include<cstring>
#define Max(a,b) (a>b?a:b)
#define Min(a,b) (a<b?a:b)
#include<cstdio>
using namespace std;
char A[1000];

int main()
{
	int len1;
	cin>>len1;
	int len = 2*len1, l, r;
	scanf("%s", A);
	int i, j, k, ans=-1;
	for(i=len1;i<len;i++) {
		A[i] = A[i-len1];
	}
	A[len] = '\0';
	char a, b;
	for(i=0;i<len-1;i++) {
		a=b='w';
		j=i, k=i+1;
		while(j>=0 && (a==A[j] || a=='w' || A[j]=='w')) {
			if(A[j]!='w') a=A[j];
			j--;
		}
		while(k<len && (b==A[k] || b=='w' || A[k]=='w')) {
			if(A[k]!='w') b=A[k];
			k++;
		}
		ans = Max(ans, k-j-1);
	} 
	cout<<Min(ans, len1);
	return 0;
}
