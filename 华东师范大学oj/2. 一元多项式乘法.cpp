#include<iostream>
#include<cstring>
#include<algorithm>
#define res register int 
#include<cstdio>
using namespace std;
struct Node{
	int ci, num;
	Node(int ci, int num):ci(ci),num(num){}
	Node():ci(0),num(0){}
	bool operator<(const Node&a)const {
		return ci>a.ci; 
	}
};

int main()
{
	char A1[105], B1[105];
	res i, j;
	while(scanf("%s %s", A1, B1)!=EOF) {
		int A[55]={0}, B[55]={0};
		int len1 = strlen(A1), len2 = strlen(B1);
		
		int ci=0, num=1, f=0;
		for(i=0;i<len1;i++) {
			if(A1[i]=='-' || A1[i]=='+') {  //+   -
				if(i!=0) {  //处理前一项 
					if(f) A[ci] -= num;
					else A[ci] += num;
					ci = 0;num = 1;
				}
				if(A1[i]=='-') f = 1;
				else f = 0;
			}
			else if(A1[i]=='x' && A1[i+1]=='^') {  //开始计算次方 
				i++;
				if(A1[i+2]>='0' && A1[i+2]<='9') {  //两位 
					ci = 10*(A1[i+1]^48) + (A1[i+2]^48);
					i += 2;
				}
				else {
					ci = A1[i+1]^48;
					i ++;
				}
			}
			else if(A1[i]=='x') ci=1;
			else {  //常数 
				num = 0;
				while(A1[i]>='0' && A1[i]<='9') {
					num = num*10+(A1[i]^48);
					i++;
				}
				i--;
			}
		}
		if(f) A[ci] -= num;
		else A[ci] += num;
		
		ci=0, num=1, f=0;
		for(i=0;i<len2;i++) {
			if(B1[i]=='-' || B1[i]=='+') {  //+   -
				if(i!=0) {  //处理前一项 
					if(f) B[ci] -= num;
					else B[ci] += num;
					ci = 0;num = 1;
				}
				if(B1[i]=='-') f = 1;
				else f = 0;
			}
			else if(B1[i]=='x' && B1[i+1]=='^') {  //开始计算次方 
				i++;
				if(B1[i+2]>='0' && B1[i+2]<='9') {  //两位 
					ci = 10*(B1[i+1]^48) + (B1[i+2]^48);
					i += 2;
				}
				else {
					ci = B1[i+1]^48;
					i ++;
				}
			}
			else if(B1[i]=='x') ci=1;
			else {  //常数 
				num = 0;
				while(B1[i]>='0' && B1[i]<='9') {
					num = num*10+(B1[i]^48);
					i++;
				}
				i--;
			}
		}
		if(f) B[ci] -= num;
		else B[ci] += num;
		
		/*for(i=50;i>=0;i--) {
			if(A[i]!=0) printf("ci=%d  %d\n", i, A[i]);
		} 
		cout<<endl;
		for(i=50;i>=0;i--) {
			if(B[i]!=0) printf("ci=%d  %d\n", i, B[i]);
		} */
		
		int ans[105]={0};
		for(i=0;i<=50;i++) {
			if(A[i]==0) continue;
			for(j=0;j<=50;j++) {
				if(B[j]!=0) {
					//cout<<i<<"  "<<j<<"  "<<A[i]<<"   "<<B[j]<<endl;
					ans[i+j] += A[i]*B[j];
				}
			}
		}
		bool ok = false;
		for(i=103;i>=0;i--) {
			if(ans[i]!=0) {
				if(ok) putchar(' ');
				printf("%d", ans[i]);
				ok = 1;
			}
		}
		if(!ok) putchar('0');
		putchar('\n'); 
	}
	return 0;
} 
