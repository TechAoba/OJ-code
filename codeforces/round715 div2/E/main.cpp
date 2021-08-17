#include <iostream>
using namespace std;
#define ll long long
ll mul[23], n, k;
const int INF = 1e18;

void solve() {

}

int main() {
    int T;
    mul[1] = 1;
    for(int i=2;i<21;i++) {
        // mul[20] = 2432902008176640000
        mul[i] = i*mul[i-1];
    }
    scanf("%d", &T);
    return 0;
}
