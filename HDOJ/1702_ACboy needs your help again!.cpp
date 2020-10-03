#include<iostream>
#include<cstdio>
#include<queue>
#include<string>
#include<stack>
using namespace std;
int K, N, add;
string str, io;

int main()
{
	cin>>K;
	while(K--) {
		cin>>N>>str;
		if(str=="FIFO") {  //∂”¡– 
			queue<int> Q;
			while(N--) {
				cin>>io;
				if(io=="IN") {
					cin>>add;
					Q.push(add);
				}
				else {
					if(Q.empty()) printf("None\n");
					else {
						printf("%d\n", Q.front());
						Q.pop();
					}
				} 
			}
		}
		else {  //’ª 
			stack<int> S;
			while(N--) {
				cin>>io;
				if(io=="IN") {
					cin>>add;
					S.push(add);
				}
				else {
					if(S.empty()) printf("None\n");
					else {
						printf("%d\n", S.top());
						S.pop();
					}
				} 
			}
		}
	}
	return 0;
}
