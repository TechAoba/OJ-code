#include<iostream>
#include<cctype>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> V;
const int MAXN = 2e5+10;
bool vis[MAXN]; 

int read() {
	bool flag = false;
	int num=0;
	char c = getchar();
	while((c<'0'||c>'9') && c!='-') c = getchar();
	if(c=='-') flag = true, c = getchar();
	while(c>='0'&& c<='9') num = (num<<3)+(num<<1)+(c^48),c = getchar();
	return flag?-num:num; 
}

int main()
{
	int N, i, j, a, ans=0;
	N = read();
	for(i=0;i<N;i++) {
		a = read();
		V.push_back(a);
		vis[a] = true;  //a存在 
	}
	if(vis[1]&&vis[2] || N==1) {cout<<1;return 0;}
	for(int cur=1;cur<V.size();cur++) {
		if(vis[V[cur]]) {  //发现一个新的天数 
			ans++;
			int t = V[cur]-1;   //t为间隔 
			for(j=t+1;j<MAXN;j+=t) {
				vis[j] = false;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
