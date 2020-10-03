#include<iostream>
using namespace std;

int main()
{
	double s, w, move = 7.0;
	cin>>s>>w;
	//bool danger = false;
	while(s>w) {
		s-=move;
		move = move*0.98;
	}
	s-=move;
	if(s>=-w) cout<<"y"<<endl;
	else cout<<"n"<<endl;
	return 0;
}
