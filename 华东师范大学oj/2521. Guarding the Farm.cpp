#include <iostream>
#include <cstdio>
using namespace std;
 
int dr[] = {-1,-1,-1, 0, 0, 1, 1, 1};
int dc[] = {-1, 0, 1,-1, 1,-1, 0, 1};
int n, m, flag;
int vis[710][710], a[710][710];
 
inline bool check(int i, int j)
{
    if(i >= 0 && i < n && j >= 0 && j < m)
    return 1;
    return 0;
}
 
void dfs(int i, int j)
{
    int x, y;
    for (int k = 0; k != 8; ++k)
    {
       x = i + dr[k];
       y = j + dc[k];
       if (check(x,y))
       {
           if (a[x][y] > a[i][j])
           flag = 0;
 
           if (!vis[x][y] && a[x][y] == a[i][j])
           {
               vis[x][y] = 1;
               dfs(x,y);
           }
       }
    }
}
 
int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i != n; ++i)
        for (int j = 0; j != m; ++j)
        {
            scanf("%d",&a[i][j]);
            vis[i][j] = 0;
        }
    int ans = 0;
    for (int i = 0; i != n; ++i)
        for (int j = 0; j != m; ++j)
        if (a[i][j] && !vis[i][j]) {
        	flag = 1;
       	 	dfs(i,j);
      	  	ans += flag;
   		 }
    printf("%d\n", ans);
    return 0;
}
