#include <iostream>
#include<cstring>
using namespace std;
bool use[1000];
int ans[1000];

int main() {
    int T, n, l, r, s;
    cin>>T;
    while(T--) {
        cin>>n>>l>>r>>s;
        int width = r-l+1;
        int minAdd = (1+width)*width/2;
        int maxAdd = (n-width+1+n)*width/2;
        if(s<minAdd || s>maxAdd) {
            printf("-1\n");
            continue;
        }
        else {
            memset(use, false, sizeof (use));
            for(int i=1;i<=width;i++) use[i] = true;
            int cha = s - minAdd;
            int left=1, right = width;
            while(cha>=width) {
                cha-=width;
                use[left++] = false;
                use[++right] = true;
            }
            int mid = right;
            while(cha--) {
                use[mid+1] = true;
                use[mid--] = false;
            }
        }
        // for(int i=1;i<=n;i++) if(use[i]) cout<<" "<<i;
        // cout<<endl;
        int idx = l, idx1=1;
        if(l==1) idx1 = r+1;
        for(int i=1;i<=n;i++) {
            if(use[i]) {
                ans[idx++] = i;
            }
            else {
                ans[idx1++] = i;
                if(idx1==l) idx1 = r+1;
            }
        }
        for(int i=1;i<=n;i++) printf("%d ", ans[i]);
        cout<<endl;
    }

    return 0;
}
