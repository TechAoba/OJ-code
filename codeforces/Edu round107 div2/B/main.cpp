#include <iostream>
#include<cmath>
#define ll long long
using namespace std;
const int MAXN = 2e5+10;
int prime[10], prime1[10];

void solve() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    if(c==1) {
        printf("%d %d\n", 2*prime[a], 2*prime1[b]);
    }
    else {
        int mul = pow(10, c-1);
        printf("%d %d\n", prime[a-c+1]*mul, prime1[b-c+1]*mul);
    }
}

int main() {
    int T;
    prime[1] = 3;
    prime1[1] = 2;
    prime[2] = 11;
    prime1[2] = 13;
    prime[3] = 103;
    prime1[3] = 193;
    prime[4] = 2333;
    prime1[4] = 3119;
    prime[5] = 10007;
    prime1[5] = 22727;
    prime[6] = 100003;
    prime1[6] = 100129;
    prime[7] = 2252927;
    prime1[7] = 1454339;
    prime[8] = 39999931;
    prime1[8] = 39999983;
    prime[9] = 100000037;
    prime1[9] =100000039;
    cin>>T;
    while(T--) {
        solve();
    }
    return 0;
}
