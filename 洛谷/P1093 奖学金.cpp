#include<iostream>
#include<algorithm>
using namespace std;
int N;
struct peo{
	int Chin, Math, Eng, id, total;
};
peo people[305];
bool cmp(peo a, peo b) {
	if(a.total>b.total) return true;
	else if(a.total==b.total && a.Chin>b.Chin) return true;
	else if(a.total==b.total && a.Chin==b.Chin && a.id<b.id) return true;
	return false;
}

int main()
{
	cin>>N;
	int i;
	for(i=1;i<=N;i++) {
		cin>>people[i].Chin>>people[i].Math>>people[i].Eng;
		people[i].total = people[i].Chin+people[i].Math+people[i].Eng;
		people[i].id = i;
	}
	sort(people+1, people+1+N, cmp);
	for(i=1;i<=5;i++) {
		cout<<people[i].id<<" "<<people[i].total<<endl;
	}
	return  0;
}
