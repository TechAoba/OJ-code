#include<iostream>
#include<cstdio>
#include<map>
#include<sstream>
#include<string>
using namespace std;
map<string,int> M;
int A[1000001];

int main()
{
	int N, i, j, cnt, len;
	string line, a, b;
	scanf("%d", &N);
	for(j=0;j<N;j++) {
		cnt = 0;
		M.clear();
		cin>>a;  getchar();
		for(i=0;i<a.length();i++) if(a[i]>='A' && a[i]<='Z') a[i] += 32;
		getline(cin, line);
		len = line.length();
		bool st = true;
		for(i=0;i<len;i++) {
			if(line[i]>='A' && line[i]<='Z') line[i] += 32;
			if(line[i]>='a' && line[i]<='z' && st) {
				A[++cnt] = i; st = 0;
			}
			else if(line[i]==' ') st=1;
		}
		stringstream ss(line);
		cnt = 0;
		while(ss>>b) {
			cnt++;
			if(!M[b]) M[b] = A[cnt]+1;
		}
		printf("case #%d:\n", j);
		if(M[a]==0) printf("None\n");
		else printf("%d\n", M[a]);
	}
	return 0;
}
