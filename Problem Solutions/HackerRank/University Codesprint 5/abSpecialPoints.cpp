#include <bits/stdc++.h>
#define MAX 9223372036854775807
#define endl "\n"
#define ll long long
#define pb push_back
#define pf pop_front
#define mp make_pair
#define loop(i,n) for(int i=0;i<n;i++)
#define fast ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)
using namespace std;
vector<int>g[300005];
vector<int> adj;
vector< pair<int, int> > mnmx;
int visited[300005];
vector<int> update;
int mn=100000000, mx=0;
void DFS(int i)
{
    //ll mn=100000000,mx=0;
    visited[i]=1;
    for(int j=0;j<g[i].size();j++)
    {
        int k =g[i][j];
        int p = adj[k];
        if(p<mn) mn=p;
        if(p>mx) mx =p;
        if(visited[k]==0) DFS(k);
    }
    //visited[i]=1;
    update.pb(i);
    //mnmx[i]= mp(mn, mx);
}
int main()
{
    fast;
    ll n,m,a,b;
    cin>>n>>m>>a>>b;
    int x,y;
    for(int i=0;i<n;i++)
        mnmx.pb(mp(-1,-1));
    for(int i=0;i<m;i++)
    {
        cin >>x>>y;
        g[x-1].pb(y-1);
        g[y-1].pb(x-1);
    }
    for(int i=0;i<n;i++)
    {
        adj.pb(g[i].size());
        /*
        cout<<g[i].size()<<"\n";
        for(int j=0;j<g[i].size();j++)
            cout<<g[i][j]<<" ";
        cout<<endl;
        */
    }
    
    for(int i=0;i<n;i++)
    {
        
        //int mn=100000000, mx=0;
        if(visited[i]==0)
        {
            DFS(i);
            for(int i=0;i<update.size();i++)
            {
                mnmx[update[i]]=mp(mn, mx);
            }
            update.clear();
            mn=100000000;
            mx=0;
        }
    }
    
    ll ans=0;
    for(int i=0;i<n;i++)
    {
        if(a*mnmx[i].first<adj[i] && adj[i]<b*mnmx[i].second) ans++;
    }
    cout<<ans<<"\n";
    return 0;
}
