#include<iostream>
using namespace std;
bool flag = false;

bool right(int a, int b, int c) {
	int A[10] = {false};
	while(a) {
		A[a%10] = A[b%10] = A[c%10] = true;
		a/=10, b/=10, c/=10;
	}
	for(int i=1;i<10;i++) if(!A[i]) return false;
	return true;
}

int main()
{
	int A, B, C, i, j, k, beishu=1;
	cin>>A>>B>>C;
	while(beishu*C<1000) {
		i = beishu*A;
		j = beishu*B;
		k = beishu*C;
		if(right(i, j, k)) {
			cout<<i<<" "<<j<<" "<<k<<endl;
			flag = true;
		}
		beishu++;
	}
	if(!flag) cout<<"No!!!"<<endl;
	return 0;
}
