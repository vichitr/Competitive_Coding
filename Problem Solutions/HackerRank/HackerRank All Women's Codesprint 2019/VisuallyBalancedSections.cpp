#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'visuallyBalancedSections' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY colors as parameter.
 */

int visuallyBalancedSections(vector<int> colors) {
    int ans = 0;
    int n = colors.size();
    for(int i=0;i<n;i++)
    {
        int f[55], even = 0, odd = 0;
        memset(f, 0, sizeof(f));
        for(int j=i;j>=0;j--)
        {
            f[colors[j]]++;
            if(f[colors[j]]==1)
                odd++;
            else if(f[colors[j]]%2==0)
            {
                odd--;
                even++;
            }
            else
            {
                even--;
                odd++;
            }
            if(odd<=1)
                ans++;
        }
    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        vector<int> colors(n);

        for (int i = 0; i < n; i++) {
            string colors_item_temp;
            getline(cin, colors_item_temp);

            int colors_item = stoi(ltrim(rtrim(colors_item_temp)));

            colors[i] = colors_item;
        }

        int result = visuallyBalancedSections(colors);

        fout << result << "\n";
    }

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
