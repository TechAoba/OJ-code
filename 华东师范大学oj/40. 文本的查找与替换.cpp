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
		a.replace(pos,b.length(),c);////���µĴ��滻��ָ���Ĵ�
		pos = a.find(b, pos);//////��������ָ���Ĵ���ֱ�����еĶ��ҵ�Ϊֹ
	}
	cout<<a<<endl;
	return 0;
}
