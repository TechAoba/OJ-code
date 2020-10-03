#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
using namespace std;
char A[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
map<char,int> M;

void print(int sum, int quan) {
	if(sum<quan) {
		printf("%c", A[sum]);
		return;
	}
	print(sum/quan, quan);
	printf("%c", A[sum%quan]);
}

int main()
{
	int sum = 0, st, en;
	char B[100];
	scanf("%d %s %d", &st, B, &en);
	int len = strlen(B), i, quan=1;
	for(i=0;i<10;i++) {
		M[i+'0'] = i;
	}
	M['A'] = 10;
	M['B'] = 11;
	M['C'] = 12;
	M['D'] = 13;
	M['E'] = 14;
	M['F'] = 15;
	for(i=len-1;i>=0;i--) {
		sum += quan*M[B[i]];
		quan *= st;
	}
	//cout<<sum<<endl;
	print(sum, en);
	return 0;
 } 
