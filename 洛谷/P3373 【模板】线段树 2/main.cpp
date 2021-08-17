#include <iostream>
#define ll long long
using namespace std;
const int MAXN = 1e5+10;
int n, m;
ll mod, num[MAXN];

struct segment_tree{
    ll sum, l, r, len, lazy_mul, lazy_add;
}tree[MAXN<<2];

void push_up(int root) {
    tree[root].sum = tree[root<<1].sum + tree[root<<1|1].sum;
}
void push_down(int root) {
    ll mul = tree[root].lazy_mul, add = tree[root].lazy_add;
    // 首先把乘法下放到子树
    tree[root<<1].lazy_mul = (tree[root<<1].lazy_mul * mul) % mod;
    tree[root<<1|1].lazy_mul = (tree[root<<1|1].lazy_mul * mul) % mod;
    tree[root<<1].lazy_add = (tree[root<<1].lazy_add * mul) % mod;
    tree[root<<1|1].lazy_add = (tree[root<<1|1].lazy_add * mul) % mod;
    tree[root<<1].sum = (tree[root<<1].sum * mul) % mod;
    tree[root<<1|1].sum = (tree[root<<1|1].sum * mul) % mod;
    tree[root].lazy_mul = 1;
    // 再下放加法
    tree[root<<1].lazy_add = (tree[root<<1].lazy_add + add) % mod;
    tree[root<<1|1].lazy_add = (tree[root<<1|1].lazy_add + add) % mod;
    tree[root<<1].sum = (tree[root<<1].sum + add * tree[root<<1].len) % mod;
    tree[root<<1|1].sum = (tree[root<<1|1].sum + add * tree[root<<1|1].len) % mod;
    tree[root].lazy_add = 0;
}

void build(int root, int l, int r) {
    tree[root].l = l;
    tree[root].r = r;
    tree[root].len = r-l+1;
    tree[root].lazy_add = 0;
    tree[root].lazy_mul = 1;
    if(l==r) {
        tree[root].sum = num[l];
        return;
    }
    int mid = (l+r)>>1;
    build(root<<1, l, mid);
    build(root<<1|1, mid+1, r);
    push_up(root);
}

void update_mul(int root, ll l, ll r, ll mul) {
    if(tree[root].r<l || tree[root].l>r) return;
    if(tree[root].l>=l && tree[root].r<=r) {
        tree[root].lazy_add = (tree[root].lazy_add * mul) % mod;
        tree[root].lazy_mul = (tree[root].lazy_mul * mul) % mod;
        tree[root].sum = (tree[root].sum * mul) % mod;
        return;
    }
    push_down(root);
    update_mul(root<<1, l, r, mul);
    update_mul(root<<1|1, l, r, mul);
    push_up(root);
}
void update_add(int root, ll l, ll r, ll add) {
    if(tree[root].r<l || tree[root].l>r) return;
    if(tree[root].l>=l && tree[root].r<=r) {
        tree[root].lazy_add = (tree[root].lazy_add + add) % mod;
        tree[root].sum = (tree[root].sum + add * tree[root].len) % mod;
        return;
    }
    push_down(root);
    update_add(root<<1, l, r, add);
    update_add(root<<1|1, l, r, add);
    push_up(root);
}

ll query(int root, ll l, ll r) {
    if(tree[root].r<l || tree[root].l>r) return 0;
    if(tree[root].l>=l && tree[root].r<=r) return tree[root].sum;
    ll ans = 0;
    push_down(root);
    ans += query(root<<1, l, r);
    ans += query(root<<1|1, l, r);
    return ans % mod;
}

int main() {
    scanf("%d %d %lld", &n, &m, &mod);
    for(int i=1;i<=n;i++) scanf("%lld", &num[i]);
    build(1, 1, n);
    int oper;
    ll l, r, k;
    while(m--) {
        scanf("%d", &oper);
        if(oper==1) {
            scanf("%lld %lld %lld", &l, &r, &k);
            update_mul(1, l, r, k);
        }
        else if(oper==2) {
            scanf("%lld %lld %lld", &l, &r, &k);
            update_add(1, l, r, k);
        }
        else {
            scanf("%lld %lld", &l, &r);
            printf("%lld\n", query(1, l, r));
        }
    }
    return 0;
}
