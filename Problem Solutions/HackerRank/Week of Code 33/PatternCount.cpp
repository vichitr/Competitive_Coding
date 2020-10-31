#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int q; cin>>q;
    while(q--)
    {
        string s, t; cin>>s;
        int ans = 0, n = s.size();
        for(int i=0;i<n;i++)
        {
            t+=s[i];
            if(s[i]=='0'){
                while(s[i]=='0')
                    i++;
                i--;
            }
        }
        for(int i=2;i<t.size();i++)
        {
            if(t[i]=='1' and t[i-1]=='0' and t[i-2]=='1')
                ans++;
        }
        // cout<<t<<endl;;
        cout<<ans<<endl;
    }
    return 0;
}
