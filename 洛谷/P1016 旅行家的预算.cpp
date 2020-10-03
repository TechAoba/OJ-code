#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio> 
using namespace std;
double D1, C, D2, P;  //油箱的容量C 每升汽油能行驶的距离D2 出发点汽油价格P 
int N;  //沿途油站数N 
const int INF = 0x3f3f3f3f;
double ans = 0.0, now = 0.0, Tmax;  //now代表目前油量 Tmax代表汽车装满油能行驶的最大距离 
struct Node{
	double dist;  //距离起始点的距离
	double price;  //每升汽油的价格 
	bool operator <(const Node &a)const {
		return dist<a.dist;
	}
};
vector<Node> V;
/*1.找到价格比当前油站价格更低的地方，加刚好能到达那里的油
  2.如果没有这样的油站就加满油到前方最低油站 
*/
int main()
{
	int i, poi = 0;
	cin>>D1>>C>>D2>>P>>N;
	V.resize(N+1);
	Tmax = C * D2;
	V[0].dist = 0, V[0].price = P;
	for(i=1;i<=N;i++) {
		cin>>V[i].dist>>V[i].price;
	}
	sort(V.begin(), V.end());
	for(i=0;i<N;i++) if(V[i].dist+Tmax<V[i+1].dist) {
		cout<<"No Solution";
		return 0;
	} 
	while(poi<=N) {
		int best = -1;
		double Tmin = INF;
		for(i=poi+1;i<=N && V[poi].dist+Tmax>=V[i].dist;i++) {  //i表示比较的油站 
			if(V[i].price < Tmin) {
				Tmin = V[i].price;
				best = i;
			}
		}
		if(best==-1) {
			double need = (D1 - V[poi].dist) / D2;
			ans += V[poi].price * (need-now);
			break;
		}
		if(Tmin<=V[poi].price) {  //加到刚好到那里的油 
			double need = (V[best].dist - V[poi].dist) / D2;
			if(need>now) {  //需要加由need-now 
				ans += V[poi].price * (need-now);
				now = 0;
				poi = best;
			}
			else {
				now -= need;
				poi = best;
			}
		}
		else {  //这里需判断能否直接到终点 
			if(V[poi].dist+Tmax>=D1) {  //可以直接到终点 
				 double need = (D1 - V[poi].dist) / D2;
				 ans += V[poi].price * (need-now);
				 break;
			} 
			else {  //加满油往best去 
				ans += V[poi].price * (C - now);
				double need = (V[best].dist - V[poi].dist) / D2;
				now = C - need;
				poi = best;
			}
		}
	}
	printf("%.2lf", ans); 
	return 0;
}
