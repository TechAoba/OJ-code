#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
const int MAXN = 2e5+10;
vector<int> edge[MAXN];
int dfn[MAXN], in[MAXN], out[MAXN], num[MAXN], tim = 0, n, m;

struct segment_tree{
    int l, r, len, mid, sum, lazy;
}tree[MAXN<<2];

void dfs(int now, int root) {
    in[now] = ++tim;
    dfn[tim] = now;
    for(int i=0;i<edge[now].size();i++) {
        int to = edge[now][i];
        if(to == root) continue;
        dfs(to, now);
    }
    out[now] = tim;
}

void push_up(int root) {
    tree[root].sum = tree[root<<1].sum + tree[root<<1|1].sum;
}
void push_down(int root) {
    if(tree[root].lazy) {
        tree[root<<1].sum = tree[root<<1].len - tree[root<<1].sum;
        tree[root<<1].lazy ^= 1;
        tree[root<<1|1].sum = tree[root<<1|1].len - tree[root<<1|1].sum;
        tree[root<<1|1].lazy ^= 1;
        tree[root].lazy = 0;
    }
}
void build(int root, int l, int r) {
    tree[root].l = l;
    tree[root].r = r;
    tree[root].lazy = 0;
    tree[root].len = r-l+1;
    if(l==r) {
        tree[root].sum = num[dfn[l]];
        return;
    }
    int mid = tree[root].mid = (l+r)>>1;
    build(root<<1, l, mid);
    build(root<<1|1, mid+1, r);
    push_up(root);
}

void update(int root, int l, int r) {
    if(tree[root].r<l || tree[root].l>r) return;
    if(tree[root].l>=l && tree[root].r<=r) {
        tree[root].sum = tree[root].len - tree[root].sum;
        tree[root].lazy ^= 1;
        return;
    }
    push_down(root);
    update(root<<1, l, r);
    update(root<<1|1, l, r);
    push_up(root);
}

int query(int root, int l, int r) {
    if(tree[root].r<l || tree[root].l>r) return 0;
    if(tree[root].l>=l && tree[root].r<=r) return tree[root].sum;
    int ans = 0;
    push_down(root);
    ans += query(root<<1, l, r);
    ans += query(root<<1|1, l, r);
    push_up(root);
    return ans;
}

int main() {
    scanf("%d", &n);
    int pa, root;
    for(int i=2;i<=n;i++) {
        scanf("%d", &pa);
        edge[i].emplace_back(pa);
        edge[pa].emplace_back(i);
    }
    for(int i=1;i<=n;i++) {
        scanf("%d", &num[i]);
    }
    dfs(1, -1);
    build(1, 1, n);
    scanf("%d", &m);
    char oper[4];
    while(m--) {
        scanf("%s %d", oper, &root);
        if(oper[0]=='p') {
            update(1, in[root], out[root]);
        }
        else {
            printf("%d\n", query(1, in[root], out[root]));
        }
    }
    return 0;
}
