#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'maximumPower' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */

int maximumPower(string s) {
    s += s;
    int ans = 0, here  = 0, n = s.size();
    for(int i=0;i<n;i++){
        if(s[i] == '0')
            here++;
        else
            here = 0;
        ans = max(ans, here);
    }
    if(ans == s.size())
        return -1;
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    int result = maximumPower(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
