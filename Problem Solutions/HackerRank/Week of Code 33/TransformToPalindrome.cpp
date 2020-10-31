#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define N 100007

vector<int> adj[N];
bool vis[N];
int c[N];
int a[1005], dp[1005][1005];

void dfs(int v, int col)
{
    vis[v] = 1;
    c[v] = col;
    for(auto i: adj[v])
        if(!vis[i])
            dfs(i, col);
}

int solve(int i, int j)
{
    if(i==j)
        return 1;
    if(i>j)
        return 0;
    int &ans = dp[i][j];
    if(ans != -1)
        return ans;
    ans = 0;
    if(a[i]==a[j])
    {
        ans = 2+solve(i+1, j-1);
    }
    ans = max(ans, solve(i+1, j));
    ans = max(ans, solve(i, j-1));
    return ans;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n, k, m; cin>>n>>k>>m;
    while(k--)
    {
        int x, y; cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    for(int i=1;i<=n;i++)
        c[i] = i;
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
            dfs(i, c[i]);
    }
    
    for(int i=0;i<m;i++){
        cin>>a[i];
        a[i] = c[a[i]];
        // cout<<
    }
    int ans = 0;
    memset(dp, -1, sizeof(dp));
    cout<<solve(0,m-1);
    return 0;
}
