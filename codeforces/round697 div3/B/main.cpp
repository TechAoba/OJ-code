#include <iostream>
using namespace std;

int main() {
    int T, n;
    cin>>T;
    while(T--) {
        cin>>n;
        int cnt = n / 2020;
        int low = cnt * 2020;
        int high = cnt * 2021;
        if(n<=high && n>=low) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
