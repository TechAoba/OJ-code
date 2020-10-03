#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char A1[10100], B1[10100];
int A[10100], B[10100], temp[10100];
int len1, len2;

int cmp() {  //ÅÐ¶ÏAÊÇ·ñ±ÈB´ó 
	len1 = strlen(A1), len2 = strlen(B1);
	if(len1>len2) return 1;
	else if(len1<len2) return -1;
	for(int i=0;i<len1;i++) {
		if(A1[i]>B1[i]) return 1;
		else if(A1[i]<B1[i]) return -1;
	}
	return 0;
}

int main()
{
	int i, j;
	scanf("%s %s", A1, B1);
	if(cmp()==0) {
		putchar('0');
		return 0;
	}
	//cout<<cmp()<<"   "<<len1<<"   "<<len2<<endl;
	if(cmp()==-1) {
		putchar('-');
		int T = len2;
		len2 = len1;
		len1 = T;
		memcpy(temp, A1, sizeof(char)*10100);
		memcpy(A1, B1, sizeof(char)*10100);
		memcpy(B1, temp, sizeof(char)*10100);
	}
	for(i=1;i<=len1;i++) A[i] = A1[len1-i]^48;
	for(i=1;i<=len2;i++) B[i] = B1[len2-i]^48;
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
	for(j=i;j>=1;j--) printf("%d", A[j]);
	return 0;
}
