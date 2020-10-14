#include<iostream>
#include<string>
using namespace std;

int main(){
	string a;
	string b;
	string c;
	getline(cin, a);
	cin>>b>>c;
	int pos;
	pos = a.find(b);
	while (pos != -1) {
		a.replace(pos,b.length(),c);////用新的串替换掉指定的串
		pos = a.find(b, pos);//////继续查找指定的串，直到所有的都找到为止
	}
	cout<<a<<endl;
	return 0;
}
