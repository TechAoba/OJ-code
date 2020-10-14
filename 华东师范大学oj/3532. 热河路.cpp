#include<iostream>
#include<cmath>
using namespace std;
int read() {
	bool flag = false;
	int num = 0;
	char c = getchar();
	while((c<'0' || c>'9' )&& c!='-') c = getchar();
	if(c=='-') flag = true, c = getchar();
	while(c>='0' && c<='9') num = (num<<3) + (num<<1) + (c^48), c = getchar();
	return flag?-num:num;
}

int main()
{
	int n = read(), a, t;
	while(n--) {
		a = read();
		t = (a-1)*2;
		t = (int)sqrt(t);
		//cout<<"tÊÇ"<<t<<endl;
		if((t+1)*t/2+1==a) printf("1\n");
		else printf("0\n");
	}
	return 0;
}
