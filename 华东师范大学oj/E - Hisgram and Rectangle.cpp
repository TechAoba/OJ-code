#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
#define LL long long
const int MAXN=100005;
LL A[MAXN],w[MAXN],h,N;
int main()
{
    	cin>>N;
    	int i;
        memset(A,-1,sizeof(A));
        int top=0;
        LL ans=0;
        for(i=1; i<=N+1; i++)
        {
            if(i!=N+1)
                cin>>h;
            else
                h=0;
            if(h>A[top])
                A[++top]=h,w[top]=1;
            else
            {
                LL cnt=0;
                while(h<=A[top])
                {
                    ans=max(ans,(w[top]+cnt)*A[top]);
                    cnt=cnt+w[top--];
                }
                A[++top]=h;
                w[top]=cnt+1;
            }
        }
        cout<<ans<<endl;
    return 0;
}
