#include<iostream>
#include<string>
#include<map>
#include<queue>
using namespace std;
map<string, bool> M;
struct Node{
	string s;
	int step;
};
int N=0, ans=0;  //N-1个规则 
string st, en;
string rule1[10], rule2[10];

void bfs() {
	queue<Node> Q;
	Q.push(Node{st, 0});
	int i, cur;
	while(!Q.empty()) {
		Node tmp = Q.front(); Q.pop();
		if(M[tmp.s]) continue;
		if(tmp.step>10) break;
		string S = tmp.s;
		if(S==en) {
			ans = tmp.step;
			break;
		}
		M[S] = true;
		for(i=0;i<N;i++) {  //N个变换规则 
			cur = 0;
			while(1) {
				int t = S.find(rule1[i], cur);
				if(t==string::npos) break;
				else {  //找到了 
					string tt = S;
					tt.replace(t, rule1[i].size(), rule2[i]);
					if(!M[tt]) {
						Q.push(Node{tt, tmp.step+1}); 
					}
				}
				cur = t+1;
			}
		}
	}
	if(ans==0 || ans>10) {
		cout << "NO ANSWER!" << endl;
	}
    else {
    	cout << ans << endl;
    }
}

int main()
{
	cin>>st>>en;
	while(cin>>rule1[N]>>rule2[N]) N++;
	bfs();
	return 0;
}
