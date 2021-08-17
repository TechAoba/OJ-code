#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5+10;
const int MAXM = 2e5+10;
const int INF = 1e9+10;
int N, M, st, en, tim;
int Distance[MAXN];

struct edge{
    int to, dist;
    edge(int to, int dist):to(to),dist(dist){}
};

struct Node{
    int step;
    int to;
    int maxVal;
    Node(int step, int to, int maxVal):step(step),to(to),maxVal(maxVal){}
};

queue<Node> que;
vector<edge> Edge[MAXN];

void solve() {
    for(int i=0;i<Edge[st].size();i++) {
        edge tmp = Edge[st][i];
        int to = tmp.to;
        int dist = tmp.dist;
        // cout<<"to="<<to<<" dist="<<dist<<endl;
        Distance[to] = dist;
        que.push(Node(1, to, dist));
    }
    while(!que.empty()) {
        Node tmp = que.front(); que.pop();
        int step = tmp.step, maxVal = tmp.maxVal, to = tmp.to;
        // cout<<step<<" "<<maxVal<<" "<<to<<" "<<Distance[to]<<endl;
        if(step>=tim) continue;
        cout<<"处理"<< to <<"节点\n";
        for(int i=0;i<Edge[to].size();i++) {
            edge tmp = Edge[to][i];
            int newTo = tmp.to;
            int dist = tmp.dist;
            int newDist = max(dist, maxVal);
            if(newDist >= Distance[newTo]) continue;
            printf("起点%d -> %d 距离更新为%d\n", to, newTo, newDist);
            Distance[newTo] = newDist;
            que.push(Node(step + 1, newTo, newDist));
        }
    }
    cout<<Distance[en]<<endl;
}


int main() {
    cin>>N>>M>>st>>en>>tim;
    int u, v, w;
    for(int i=0;i<MAXN;i++) Distance[i] = INF;
    Distance[st] = 0;
    for(int i=0;i<M;i++) {
        scanf("%d %d %d", &u, &v, &w);
        Edge[u].push_back(edge(v, w));
        Edge[v].push_back(edge(u, w));
    }
    solve();
    return 0;
}
