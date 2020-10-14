#include<iostream>
#include<queue>
#include<map>
#include<string>
using namespace std;
map<string,bool> Map;
int ans;
string s1;
struct Node{
	string s;
	int step;
	Node(string s, int step):s(s),step(step){}
};
queue<Node> Q;
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

void bfs() {
	int poi, i, r, c, r1, c1, xu1, xu2, ste;  //两个字母的序号 
	string ts;
	char t;
	while(!Q.empty()) {
		Node T = Q.front(); Q.pop();
		if(T.s=="123456780") {
			ans=T.step; break;
		}
		ts = T.s, ste=T.step;
		for(i=0;i<9;i++) if(ts[i]=='0') poi=i;  //得到0的序号 
		r=poi/3, c=poi%3;
		for(i=0;i<4;i++) {//上下左右走 
			r1=r+dr[i]; c1=c+dc[i];
			if(r1<0||r1>2||c1<0||c1>2) continue;
			xu1=r*3+c, xu2=r1*3+c1;
			t=ts[xu1], ts[xu1]=ts[xu2], ts[xu2]=t;
			if(!Map[ts]) {
				Map[ts]=true;
				Q.push(Node(ts, ste+1));
			}
			t=ts[xu1], ts[xu1]=ts[xu2], ts[xu2]=t;
		}
	}
}

int main()
{
	int a;
	for(int i=0;i<9;i++) {
		cin>>a;
		s1+=a+'0';
	}
	Map[s1]=true;
	Q.push(Node(s1, 0));
	bfs();
	cout<<ans<<endl;
	return 0;
}
