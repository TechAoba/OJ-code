#include<iostream>
#include<cstring>
using namespace std;
int N, Na, Nb;
int score[5][5], A[205], B[205], ansA = 0, ansB = 0;

int main()
{
	int i, j, ca=0, cb=0;
	memset(score, -1, sizeof(score));
	for(i=0;i<5;i++) score[i][i] = 0;
	score[0][2] = score[0][3] = score[1][3] = score[2][4] = score[3][4] = 1;
	for(i=1;i<5;i++) {
		for(j=0;j<i;j++) {
			score[i][j] = 1;
		}
	}
	score[2][0] = score[3][0] = score[3][1] = score[4][2] = score[4][3] = -1;
	cin>>N>>Na>>Nb;
	for(i=0;i<Na;i++) cin>>A[i];
	for(i=0;i<Nb;i++) cin>>B[i];
	for(i=0;i<N;i++) {
		//cout<<"a出"<<A[ca]<<",B出"<<B[cb]<<endl;
		int tmp = score[A[ca++]][B[cb++]];
		if(tmp==1) {
			ansA++;
		//	cout<<"A胜利"<<endl;
		}
		else if(tmp==-1) {
			ansB++;
		//	cout<<"B胜利"<<endl;
		}
		ca %= Na;
		cb %= Nb;
	}
	cout<<ansA<<" "<<ansB;
	return 0;
} 
