#include <iostream>
#define ll long long
using namespace std;
const int MAXN = 1e5+10;
ll num[MAXN];

struct segment_tree{
    ll l, r, mid, lazy, len, sum;
}tree[MAXN<<2];

void push_up(int root) {
    tree[root].sum = tree[root<<1].sum + tree[root<<1|1].sum;
}
void push_down(int root) {
    tree[root<<1].lazy += tree[root].lazy;
    tree[root<<1].sum += tree[root<<1].len * tree[root].lazy;
    tree[root<<1|1].lazy += tree[root].lazy;
    tree[root<<1|1].sum += tree[root<<1|1].len * tree[root].lazy;
    tree[root].lazy = 0;
}
void build(int root, int l, int r) {
    tree[root].l = l;
    tree[root].r = r;
    tree[root].len = r-l+1;
    tree[root].lazy = 0;
    if(l==r) {
        tree[root].sum = num[l];
        return;
    }
    ll mid = tree[root].mid = (l+r)>>1;
    build(root<<1, l, mid);
    build(root<<1|1, mid+1, r);
    push_up(root);
}

void update(int root, int l, int r, int z) {
    if(tree[root].l>r || tree[root].r<l) return;
    if(tree[root].l>=l && tree[root].r<=r) {
        tree[root].lazy += z;
        tree[root].sum += tree[root].len * z;
        return;
    }
    push_down(root);
    update(root<<1, l, r, z);
    update(root<<1|1, l, r, z);
    push_up(root);
}

ll query(int root, int l, int r) {
    if(tree[root].l>r || tree[root].r<l) return 0;
    if(tree[root].l>=l && tree[root].r<=r) return tree[root].sum;
    ll ans = 0;
    push_down(root);
    ans += query(root<<1, l, r);
    ans += query(root<<1|1, l, r);
//    push_up(root);
    return ans;
}

int main() {
    int n, m, l, r, k;
    scanf("%d %d", &n, &m);
    for(int i=1;i<=n;i++) scanf("%lld", &num[i]);
    build(1, 1, n);
    int oper;
    for(int i=0;i<m;i++) {
        scanf("%d", &oper);
        if(oper == 1) {
            scanf("%d %d %d", &l, &r, &k);
            update(1, l, r, k);
        }
        else {
            scanf("%d %d", &l, &r);
            printf("%lld\n", query(1, l, r));
        }
    }
    return 0;
}
