#include<iostream>
#include<cmath> 
#include<cstdio>
using namespace std;

int main()
{
	int M, i;
	cin>>M;
	M *= 2;
	for(int X = (int)(sqrt(M)+0.5);X>1;X--) {
		int Y = M/X;
		if(M%X==0 && (X+Y)&1) {
			printf("%d %d\n", (Y-X+1)/2, (X+Y-1)/2);
		}
	}
	
	return 0;
}
