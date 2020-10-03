#include<iostream>
#include<cstdio>
#define LL long long
#define Max(a,b) (a>b?a:b)
#define res register int
using namespace std;
const LL INF = -0x7fffffff;
int N, D, cnt=0, tree[800005];

void add(int l, int r, int p, int num) {
	if(l==r) {
		tree[p] = num;
		return;
	}
	int mid = (l+r)>>1;
	if(mid>=cnt) add(l, mid, p<<1, num);
	if(mid<cnt) add(mid+1, r, p<<1|1, num);
	tree[p] = Max(tree[p<<1], tree[p<<1|1])%D;
}

LL get(int L, int R, int l, int r, int p) {
	if(l>=L && r<=R) return tree[p];
	int mid = (l+r)>>1;
	LL a = INF, b = INF;
	if(mid>=L) a = get(L, R, l, mid, p<<1);
	if(mid<R) b = get(L, R, mid+1, r, p<<1|1);
	return Max(a,b);
}

int main()
{
	char op[2];
	LL x, t=0;
	scanf("%d %d", &N, &D);
	for(res i=1;i<=N;i++) {
		//cout<<"i = "<<i<<endl;
		scanf("%s %lld", &op, &x);
		if(op[0]=='A') {  //add
			cnt++;
			add(1, N, 1, (x+t)%D);
		//	cout<<tree[2]<<endl;
		}
		else {
			t = get(cnt-x+1, cnt, 1, N, 1);
			printf("%lld\n", t);
		}
	}
	/*cout<<tree[1]<<endl;
	cout<<tree[2]<<endl;
	cout<<tree[3]<<endl;*/
	return 0;
}
