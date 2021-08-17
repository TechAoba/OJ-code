#include <iostream>
#include<vector>
using namespace std;
const int MAXN = 3e5+10;
int n;
char s[3][MAXN], ans[MAXN];

void make_up(int id1, int id2, char num) {
    char add = '0';
    if(num=='0') add = '1';
    vector<int> poi1, poi2;
    poi1.emplace_back(-1);
    poi2.emplace_back(-1);
    int en = 2*n, idx = 0, tmp1=0, tmp2=0;
    for(int i=0;i<en;i++) {
        if(s[id1][i] == num) poi1.emplace_back(i);
    }
    for(int i=0;i<en;i++) {
        if(s[id2][i] == num) poi2.emplace_back(i);
    }
    int ma = min(poi1.size(), poi2.size());
    for(int i=1;i<ma;i++) {
        int cnt = max(poi1[i]-poi1[i-1], poi2[i]-poi2[i-1]) - 1;
        tmp1 = poi1[i], tmp2 = poi2[i];
        while(cnt-- > 0) ans[idx++] = add;
        ans[idx++] = num;
    }
    for(int j = tmp1+1;j<en;j++) ans[idx++] = s[id1][j];
    for(int j = tmp2+1;j<en;j++) ans[idx++] = s[id2][j];
    ans[idx] = '\0';
}

void solve() {
    scanf("%d", &n);
    scanf("%s %s %s", s[0], s[1], s[2]);
    vector<int> vec0, vec1;
    for(int i=0;i<3;i++) {
        int cnt1=0, cnt0=0;
        for(int j=n*2-1;j>=0;j--) {
            if(s[i][j]=='1') cnt1++;
            else cnt0++;
        }
        if(cnt0>=n) vec0.emplace_back(i);
        else vec1.emplace_back(i);
    }
    if(vec0.size()>1) {
        make_up(vec0[0], vec0[1], '0');
    }
    else {
        make_up(vec1[0], vec1[1], '1');
    }
    printf("%s\n", ans);
}

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        solve();
    }
    return 0;
}
