#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int K;
char A[260];
int top[10] = {1, 0, 1, 1, 0, 1, 1, 1, 1, 1};
int zs[10] = {1, 0, 0, 0, 1, 1, 1, 0, 1, 1};
int ys[10] = {1, 1, 1, 1, 1, 0, 0, 1, 1, 1};
int mid[10] = {0, 0, 1, 1, 1, 1, 1, 0, 1, 1};
int zx[10] = {1, 0, 1, 0, 0, 0, 1, 0, 1, 0};
int yx[10] = {1, 1, 0, 1, 1, 1, 1, 1, 1, 1};
int bot[10] = {1, 0, 1, 1, 0, 1, 1, 0, 1, 1};

int main()
{
	cin>>K;
	scanf("%s", A);
	int i, j, k, len = strlen(A);
	for(i=0;i<len;i++) {
		if(i) putchar(' ');  //¼ä¸ô
		putchar(' ');  //×ó 
		if(top[A[i]-'0']) {
			for(j=0;j<K;j++) {
				putchar('-');
			}
		}
		else {
			for(j=0;j<K;j++) {
				putchar(' ');
			}
		}
		putchar(' ');  //ÓÒ 
	}
	putchar('\n');
	for(k=0;k<K;k++) {
		for(i=0;i<len;i++) {
			if(i) putchar(' ');  //¼ä¸ô
			if(zs[A[i]-'0']) putchar('|');
			else putchar(' ');
			for(j=0;j<K;j++) putchar(' ');
			if(ys[A[i]-'0']) putchar('|');
			else putchar(' ');
		}
		putchar('\n');
	}
	for(i=0;i<len;i++) {
		if(i) putchar(' ');  //¼ä¸ô
		putchar(' ');  //×ó 
		if(mid[A[i]-'0']) {
			for(j=0;j<K;j++) {
				putchar('-');
			}
		}
		else {
			for(j=0;j<K;j++) {
				putchar(' ');
			}
		}
		putchar(' ');  //ÓÒ 
	}
	putchar('\n');
	for(k=0;k<K;k++) {
		for(i=0;i<len;i++) {
			if(i) putchar(' ');  //¼ä¸ô
			if(zx[A[i]-'0']) putchar('|');
			else putchar(' ');
			for(j=0;j<K;j++) putchar(' ');
			if(yx[A[i]-'0']) putchar('|');
			else putchar(' ');
		}
		putchar('\n');
	}
	for(i=0;i<len;i++) {
		if(i) putchar(' ');  //¼ä¸ô
		putchar(' ');  //×ó 
		if(bot[A[i]-'0']) {
			for(j=0;j<K;j++) {
				putchar('-');
			}
		}
		else {
			for(j=0;j<K;j++) {
				putchar(' ');
			}
		}
		putchar(' ');  //ÓÒ 
	}
	putchar('\n');
	return 0;
}
