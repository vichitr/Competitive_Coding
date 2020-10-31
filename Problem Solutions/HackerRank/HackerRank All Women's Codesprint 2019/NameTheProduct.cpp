#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'productName' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING_ARRAY names as parameter.
 */

string productName(vector<string> names) {
    string ans;
    int n = names.size();
    for(int i=0;i<5;i++)
    {
        int f[26];
        memset(f, 0, sizeof(f));
        for(int j=0;j<n;j++)
        {
            f[names[j][i]-'a']++;
        }
        int p = 0, mn = n+1;
        for(int j=0;j<26;j++)
        {
            if(f[j]<=mn)
            {
                mn = f[j];
                p = j;
            }
        }
        ans += string(1, char(p+'a'));
    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<string> names(n);

    for (int i = 0; i < n; i++) {
        string names_item;
        getline(cin, names_item);

        names[i] = names_item;
    }

    string result = productName(names);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
