#include<stdio.h>
#define lowbit(a) (-a&a)

int main()
{
	int a;
	while(scanf("%d", &a)==1 && a) {
		printf("%d\n", lowbit(a));
	}
	return 0;
}
