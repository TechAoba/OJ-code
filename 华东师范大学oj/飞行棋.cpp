#include<bits/stdc++.h> 
using namespace std;
int n,m;
int vis[10005];
vector<int>V[10005];
struct node{
	int x;
	int step;
};
int ans;
void run()
{
	queue<node>Q;
	node t;
	t.x=t.step=0; 
	Q.push(t);
	while(!Q.empty())
	{
		t=Q.front();
		Q.pop();
		if(t.x==n*m)
		{
			if(ans==-1)
				ans=t.step;
			else
				ans=min(ans,t.step);
			continue;
		}
		if(ans!=-1 && t.step>ans)
			continue;
		
		for(int i=0;i<=6;i++)
		{
			int temp=t.x+i;
			if(temp>n*m)
				break;
			if(vis[temp])
				continue;
			if(V[temp].size()>0)
			{
				for(int j=0;j<V[temp].size();j++)
				{
					int vx=V[temp][j];
					if(vis[vx])
						continue;
					node L;
					L.x=vx;
					if(i==0)
						L.step=t.step;
					else
						L.step=t.step+1;
					Q.push(L);
				}	
				vis[temp]=1;
			}
			else
			{
				node L;
				L.x=temp;
				L.step=t.step+1;
				Q.push(L);
			}
			
		}		vis[t.x]=1; 	
	}
}
int main()
{
	int p,q,u,v;
	while(scanf("%d%d%d%d",&n,&m,&p,&q)!=EOF)
	{
		for(int i=0;i<=m*n;i++)
		{
			vis[i]=0;
			V[i].clear();
		}
		for(int i=0;i<p;i++)
		{
			scanf("%d%d",&u,&v);
			V[u].push_back(v); 
		}
		for(int i=0;i<q;i++)
		{
			scanf("%d%d",&u,&v);
			V[u].push_back(v);
		}
		ans=-1;
		run();
		printf("%d\n",ans);	
	}
	return 0;
}
