#include<iostream>
#include<string>
#include<sstream>
#include<cstdio>
#include<map>
using namespace std;

map<string,int> M;

int main()
{
	int i, N;
	string line, a, b;
	scanf("%d\n", &N);
	for(i=0;i<N;i++) {
		getline(cin, line);
		M.clear();
		stringstream ss(line);
		while(ss>>a) M[a]++;
		cin>>b;
		getchar();
		printf("case #%d:\n%d\n", i, M[b]);
	}
	return 0;
}
