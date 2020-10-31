#include <bits/stdc++.h>
using namespace std;
#define ip pair<int, int>
#define pb push_back

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    vector<ip> v1, v2;
    int n, x; cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        v1.pb({x, i});
    }
    for(int i=0;i<n;i++)
    {
        cin>>x;
        v2.pb({x, i});
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    int ans;
    if(v1[0].second != v2[0].second)
        ans = v1[0].first+v2[0].first;
    else{
        ans = min(v1[0].first+v2[1].first, v1[1].first+v2[0].first);
    }
    cout<<ans;
    return 0;
}
