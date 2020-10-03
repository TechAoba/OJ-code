#include<iostream>
#include<cstdio>
using namespace std;
const int maxn = 100000+10;
int A[maxn], N;

void quicksort(int *A, int l, int r) {
	if(l>=r) return;
	int mid = l+((r-l)>>1); 
	if(A[mid]>A[r]) swap(A[mid], A[r]);
	if(A[l]>A[r]) swap(A[l], A[r]);  //上面两个使A[r]最大
	if(A[mid]>A[l]) swap(A[mid], A[l]);  //使A[l]>=A[mid] 
	int val = A[l];  //l位置上的值作为比较值
	int i=l, j=r;  //i, j两个哨兵
	while(i<j) {
		while(A[j] >= val && j>i) j-- ;
		if(i<j) {
			A[i] = A[j];
			i++;
			while(A[i] <= val && j>i) i++;
			if(i<j) {
				A[j] = A[i];
				j--;
			}
		}
	} 
	A[i] = val;
	quicksort(A, l, i-1);
	quicksort(A, i+1, r);
}

int main()
{
	cin>>N;
	int cnt = 0;
	for(int i=1;i<=N;i++) {
		scanf("%d", &A[i]);
		if(A[i-1]>A[i]) cnt++;
	}
	if(cnt) quicksort(A, 1, N);
	for(int j=1;j<N;j++) {
		printf("%d ", A[j]);
	}
	printf("%d\n", A[N]);
	return 0;
}
