#include<iostream>
#include<cstring>
using namespace std;
int R, N;
bool vis[1005];
int A[1005];

int main() 
{
	memset(A, -1, sizeof(A));
	cin>>R>>N;
	int i, val, cur = 0, ans = 0;  //0  --  R-1
	for(i=0;i<N;i++) {
		cin>>val;
		if(!vis[val]) {  //不存在于机器中 
			ans++;
			vis[val] = true;
			if(A[cur]>=0) {
				vis[A[cur]] = false;  //清出去 
			}
			A[cur++] = val;
			if(cur>=R) cur-=R;
		}
	}
	cout<<ans;
	return 0;
}
