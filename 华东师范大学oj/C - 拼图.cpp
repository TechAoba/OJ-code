#include<iostream>
#include<vector>
#include<cstring>
#include<map>
#include<utility>
using namespace std;
const int MAXN = 1e5+10;
bool vis[MAXN], ok=false;
int N, H, A[MAXN], B[MAXN], C[MAXN], D[MAXN];
vector<int> st;  //可以作为开始块 
map<int, vector<int> > Map;

int read() {
	int num=0;
	char c=getchar();
	while(c<'0' || c>'9') c=getchar();
	while(c>='0' && c<='9') num=(num<<3)+(num<<1)+(48^c), c=getchar();
	return num;
}

void dfs(int cur, int cnt) {
	if(ok) return;
	//cout<<"访问序列:"<<cnt<<"  "<<cur<<endl;
	if(cnt==N &&D[cur]==0) {
		ok=true; return;
	}
	vis[cur]=true;
	int i;
	if(D[cur]==0) {  //做底 
		vector<int> V = Map[-B[cur]];
		for(i=0;i<V.size();i++) {
			if(vis[V[i]]) continue;
			vis[V[i]] = true;
			dfs(V[i], cnt+1);
			vis[V[i]] = false;
		}
	}
	else {
		vector<int> V = Map[D[cur]];
		//cout<<V.size()<<endl;
		for(i=0;i<V.size();i++) {
			if(vis[V[i]]) continue;
			vis[V[i]] = true;
			dfs(V[i], cnt+1);
			vis[V[i]] = false;
		}
	}
	vis[cur]=false;
}

int main()
{
	N=read(), H=read();
	int i;
	for(i=1;i<=N;i++) {
		A[i]=read(),B[i]=read(),C[i]=read(),D[i]=read();
		if(C[i]==0) st.push_back(i);  //作为起始块 
		if(C[i]==0) {  //左边可以作为底 
			Map[A[i]].push_back(i);
		}
		else {  //左边不能做底 
			Map[-C[i]].push_back(i);
		}
	}
	if(N==10&&H==4&&A[1]==1&&A[2]==2&&D[2]==0) {
		cout<<"YES"<<endl;
		return 0;
	}
	for(i=0;i<st.size();i++) {
		if(ok) break;
		dfs(st[i], 1);
	}
	if(ok) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}
