#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int Tmax=1, Tmin=1, N, A[130], B[130], len1, len2;
char T[55][130];

int cmp(int a, int b) {  //ÅÐ¶ÏT[a]ÊÇ·ñ±ÈT[b]´ó 
	int len1 = strlen(T[a]), len2 = strlen(T[b]);
	if(len1>len2) return 1;
	else if(len1<len2) return -1;
	for(int i=0;i<len1;i++) {
		if(T[a][i]>T[b][i]) return 1;
		else if(T[a][i]<T[b][i]) return -1;
	}
	return 0;
}

int main()
{
	scanf("%d", &N);
	int i;
	for(i=1;i<=N;i++) {
		scanf("%s", T[i]);
		if(cmp(i, Tmax)==1) Tmax = i;
		if(cmp(Tmin, i)==1) Tmin = i;
	}
	len1 = strlen(T[Tmax]), len2 = strlen(T[Tmin]);
	for(i=1;i<=len1;i++) A[i] = T[Tmax][len1-i]^48;
	for(i=1;i<=len2;i++) B[i] = T[Tmin][len2-i]^48;
	for(i=1;i<=len2;i++) A[i] -= B[i];
	for(i=1;i<=len1;i++) {
		if(A[i]<0) {
			A[i] += 10;
			A[i+1] -= 1; 
		}
	}
	for(i=len1;i>1;i--) {
		if(A[i]!=0) break;
	}
	for(int j=i;j>=1;j--) printf("%d", A[j]);
	return 0;
}
