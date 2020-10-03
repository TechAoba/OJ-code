#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#define Min(a,b) (a<b?a:b)
#define res register int
using namespace std;
const int MAXN = 100005, L=-1, R=1;
int N;

struct Node{
	double x, y;
	int index;
}node[MAXN], A[MAXN];
bool cmp_x(Node a, Node b) {  //根据x进行排序 
	if(a.x==b.x) return a.y<b.y;
	return a.x<b.x;
}
bool cmp_y(Node a, Node b) {  //根据y进行排序 
	if(a.y==b.y) return a.x<b.x;
	return a.y<b.y;
}
inline double getDis(Node a, Node b) {
	double sub_x = a.x-b.x;
	double sub_y = a.y-b.y;
	return sqrt(sub_x*sub_x+sub_y*sub_y);
}

double divide_solve(int Left, int Right) {
	int cnt = Right-Left+1;
	if(cnt==1) return 0;
	else if(cnt==2) return getDis(node[Left], node[Left+1]);
	else if(cnt==3) {  //三个 
		double ans1 = getDis(node[Left], node[Left+1]);
		double ans2 = getDis(node[Left], node[Left+2]);
		double ans3 = getDis(node[Left+1], node[Left+2]);
		return Min(ans1, Min(ans2, ans3));
	}
	int Mid = (Left+Right)>>1;
	double ansL = divide_solve(Left, Mid);
	double ansR = divide_solve(Mid+1, Right);
	double ans = Min(ansL, ansR);  //目前最小距离 
	res i, j, id=0;
	double posL = node[Mid].x-ans;
	double posR = node[Mid].x+ans;
	for(i=Mid;i>=Left && node[i].x>posL;i--) {
		A[id].index = L;
		A[id].x = node[i].x;
		A[id++].y = node[i].y;
	}
	for(i=Mid+1;i<=Right && node[i].x<posR;i++) {
		A[id].index = R;
		A[id].x = node[i].x;
		A[id++].y = node[i].y;
	}
	sort(A, A+id, cmp_y);
	for(i=0;i<id;i++) {
		if(A[i].index==R) continue;
		for(j=1;j<=7 && i+j<id;j++) {
			if(A[i+j].index==L) continue;
			ans = Min(ans, getDis(A[i], A[i+j]));
		}
	}
	return ans;
}

int main()
{
	res i;
	while(scanf("%d", &N)==1 && N!=0) {
		for(i=0;i<N;i++) scanf("%lf %lf", &node[i].x, &node[i].y);
		sort(node, node+N, cmp_x);  //首先根据x来排序
		printf("%.2lf\n", divide_solve(0, N-1)/2);
	}
	return 0;
 } 
