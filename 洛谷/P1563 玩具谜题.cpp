#include<iostream>
#include<string>
using namespace std;
const int maxn = 1e5+10;
int jia[maxn];  //向左为加 
string career[maxn];
int N, M;

int main()
{
	cin>>N>>M;
	int i, dir, num, cur = 0;
	for(i=0;i<N;i++) {
		cin>>jia[i]>>career[i];
	}
	for(i=0;i<M;i++) {
		cin>>dir>>num;
		dir = (dir+jia[cur])%2;  //0减  1加 
		if(dir) {
			cur += num;
			cur%=N;
		}
		else {
			cur -= num;
			if(cur<0) cur+=N;
		}
		//cout<<career[cur]<<endl;
	}
	cout<<career[cur];
	return 0;
}
