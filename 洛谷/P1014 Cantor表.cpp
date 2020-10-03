#include<iostream>
#include<cstdio>
using namespace std;

int midFind(int n) {
	int low = 0, high = 4000, mid;
	while(low<=high) {
		mid = (low+high)/2;
		int Temp = mid*(mid+1)/2;
		if(Temp<n) low = mid+1;
		else high = mid-1;
	}
	mid--;
	if((mid+1)*(mid+2)/2 < n) mid++;
	return mid; 
}

int main()
{
	int N, add;
	cin>>N;
	add = midFind(N);
	N -= (add+1)*add/2;  //addÅ¼Êı  ÓÒÉÏ 
	if(add%2==0) {
		printf("%d/%d\n", add+2-N, N);
	}
	else {
		printf("%d/%d\n", N, add+2-N);
	}
	return 0;
}
