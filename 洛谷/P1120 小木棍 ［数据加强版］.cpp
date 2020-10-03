#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#define Max(a,b) (a>b?a:b)
#define Min(a,b) (a<b?a:b)
#define res register int
using namespace std;
int N, A[70], Next[70], cnt=0, Tmax=-0x3f3f3f3f, Tmin=0x3f3f3f3f, target;
bool vis[70], ok=false;
bool cmp(int a, int b) {
	return a>b;
}

int read() {
	int x=0, f=1;
	char c=getchar();
	while(c<'0' || c>'9') {if(c=='-')f=-1;c=getchar();}
	while(c>='0' && c<='9') {x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return x*f;
}

void dfs(int last, int num, int sheng) {  //last上一根处理  sheng代表剩余 
	if(ok) return;
	if(num==cnt) {  //满足条件 
		ok = true;
		return;
	}
	res l = last+1, r = cnt-1, mid;
	res j;
	if(!sheng) {  //处理下一根棒子 
		for(j=1;j<cnt;j++) if(!vis[j]) break;
		vis[j] = true;
		dfs(j, num+1, target-A[j]);
		if(ok) return;
		vis[j] = false;
	}
	while(l<r) {
		mid = (l+r)>>1;
		if(A[mid]<=sheng) r=mid;
		else l = mid+1;
	}
	for(res i=l;i<cnt;i++) {
		if(vis[i]) continue;  //使用过 
		vis[i] = true;
		dfs(i, num+1, sheng-A[i]);
		if(ok) return;
		vis[i] = false;
		if(sheng==A[i] || sheng==target) return;
		i=Next[i];
	}
}

int main()
{
	while(1) {
		res i;
		int a, sum=0;
		cnt=0;
		Tmax = -0x3f3f3f3f;
		N = read();
		if(!N) break;
		ok = false;
		memset(vis, false, sizeof(vis));
		for(i=0;i<N;i++) {
			a = read();
			if(a<=50) {
				A[cnt++] = a;
				sum += a;
				Tmax = Max(Tmax, a);
			}
		}
		sort(A, A+cnt, cmp);
		Next[cnt-1] = cnt;
		for(i=cnt-2;i>=0;i--) {  //处理下一个 
			if(A[i]==A[i+1]) Next[i] = Next[i+1];
			else Next[i] = i;
		}
		for(target=Tmax;target<=sum/2;target++) {
			if(sum%target!=0) continue;
			vis[0] = true;
			dfs(0, 1, target-A[0]);
			vis[0] = false;
			if(ok) {
				printf("%d\n", target);
				break;
			}
		}
		if(!ok) printf("%d\n", sum);
	}
	return 0;
}
