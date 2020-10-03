#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio> 
using namespace std;
double D1, C, D2, P;  //���������C ÿ����������ʻ�ľ���D2 ���������ͼ۸�P 
int N;  //��;��վ��N 
const int INF = 0x3f3f3f3f;
double ans = 0.0, now = 0.0, Tmax;  //now����Ŀǰ���� Tmax��������װ��������ʻ�������� 
struct Node{
	double dist;  //������ʼ��ľ���
	double price;  //ÿ�����͵ļ۸� 
	bool operator <(const Node &a)const {
		return dist<a.dist;
	}
};
vector<Node> V;
/*1.�ҵ��۸�ȵ�ǰ��վ�۸���͵ĵط����Ӹպ��ܵ����������
  2.���û����������վ�ͼ����͵�ǰ�������վ 
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
		for(i=poi+1;i<=N && V[poi].dist+Tmax>=V[i].dist;i++) {  //i��ʾ�Ƚϵ���վ 
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
		if(Tmin<=V[poi].price) {  //�ӵ��պõ�������� 
			double need = (V[best].dist - V[poi].dist) / D2;
			if(need>now) {  //��Ҫ����need-now 
				ans += V[poi].price * (need-now);
				now = 0;
				poi = best;
			}
			else {
				now -= need;
				poi = best;
			}
		}
		else {  //�������ж��ܷ�ֱ�ӵ��յ� 
			if(V[poi].dist+Tmax>=D1) {  //����ֱ�ӵ��յ� 
				 double need = (D1 - V[poi].dist) / D2;
				 ans += V[poi].price * (need-now);
				 break;
			} 
			else {  //��������bestȥ 
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
