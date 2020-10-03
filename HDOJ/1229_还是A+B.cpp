#include<iostream>
#include<cstdio>
using namespace std;

bool fun(int a, int b, int k) {
	bool ok = true;  //ÊÇÒ»Ñù 
	while(k--) {
		if(a%10 != b%10) {
			ok = false;
			break;
		}
		a/=10;
		b/=10;
	} 
	return ok;
} 

int main()
{
	int a, b, k;
	while(scanf("%d %d %d", &a, &b, &k) != EOF) {
		if(!(a|b)) break;
		if(fun(a, b, k)) printf("-1\n");
		else printf("%d\n", a+b);
	}
	return 0;
}
