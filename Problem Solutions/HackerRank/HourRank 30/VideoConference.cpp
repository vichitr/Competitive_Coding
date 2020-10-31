#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define FastRead ios_base::sync_with_stdio(0);cin.tie(nullptr);cout.tie(nullptr);

int main(){

    FastRead;
    ll n;
    cin>>n;

    string s[n];

    map<string,ll> mm,mm2;
    for(ll i=0;i<n;i++){
        cin>>s[i];
        mm[s[i]]++;
        mm2[s[i]]++;
    }

    string ans[n];
    map<string,ll> m;

    for(ll i=0;i<n;i++){
        string ss = "";
        string s1 = "";
        bool flag = false;
        for(ll j=0;j<s[i].length();j++){
            ss += s[i][j];
            if(!m[ss] && !flag){
                m[ss] = 1;
                flag = true;
                s1 = ss;
            }else {
                m[ss] = 1;
            }
        }

        if(!flag && (mm2[s[i]]-mm[s[i]]+1 != 1)){
            s1 += s[i] + " " + to_string(mm2[s[i]]-mm[s[i]]+1);
        }else if(!flag){
            s1 = s[i];
        }
        mm[s[i]]--;
        ans[i] = s1;
    }

    for(ll i=0;i<n;i++){
        cout<<ans[i]<<endl;
    }
}
