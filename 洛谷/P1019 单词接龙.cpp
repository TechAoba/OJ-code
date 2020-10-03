#include<iostream>
#include<string>
#include<cstring>
#define Max(a,b) (a>b?a:b)
using namespace std;
string S[25];
int use[25], len=0, ans=0, N;

void dfs(int Now) {
	string now = S[Now];
	int i, j, Tlen = now.length();
	ans = Max(ans, len);
	for(i=1;i<=N;i++) {
		if(use[i]>=2) continue;
		int len1 = S[i].length();  //ѡ��ĳ��� 
		for(j=Tlen-1;j>=1;j--) {  //�Ӻ���ǰ�� 
			string tmp = now.substr(j);
			//cout<<"��"<<j<<"����ʼ  "<<tmp<<endl;
			if(Tlen-j >= len1) continue;  //�����
			if(tmp == S[i].substr(0, Tlen-j)) {  //�������� 
				use[i]++;
				len += len1-Tlen+j;
				dfs(i);
				len -= len1-Tlen+j;
				use[i]--;
				break;
			} 
		}
	}
}

int main()
{
	cin>>N;
	int i;
	for(i=1;i<=N;i++) cin>>S[i];
	char c;
	cin>>c;
	for(i=1;i<=N;i++) {
		if(c==S[i][0]) {
			memset(use, 0, sizeof(use));
			len = S[i].size();
			use[i] = 1;
			dfs(i);
		}
	}
	cout<<ans;
	return 0;
}
