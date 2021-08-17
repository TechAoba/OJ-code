#include <iostream>
#include<string>
using namespace std;

int main() {
    int T, N;
    cin>>T;
    string s;
    while(T--) {
        cin>>N;
        int x1=-1, y1=-1, x2=-1, y2=-1, x3, y3, x4, y4;
        for(int i=0;i<N;i++) {
            cin>>s;
            for(int j=0;j<N;j++) {
                if(s[j]=='*') {
                    if(x1==-1) {
                        x1=i, y1=j;
                    }
                    else{
                        x2=i, y2=j;
                    }
                }
            }
        }
        if(x1==x2) {
            if(x1==0) x3 = x4 = 1;
            else x3 = x4 = 0;
            y3=y1, y4=y2;
        }
        else if(y1==y2) {
            if(y1==0) y3 = y4 = 1;
            else y3 = y4 = 0;
            x3=x1, x4=x2;
        }
        else {
            x3=x1, y3=y2;
            x4=x2, y4=y1;
        }
        for(int i=0;i<N;i++) {
            for(int j=0;j<N;j++) {
                if(i==x1&&j==y1||i==x2&&j==y2||i==x3&&j==y3||i==x4&&j==y4) printf("*");
                else printf(".");
            }
            putchar('\n');
        }
    }
    return 0;
}
