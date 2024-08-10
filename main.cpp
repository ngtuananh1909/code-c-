#include <bits/stdc++.h>
#define sync ios_base::sync_with_stdio(false); cin.tie(0);cout.tie(0);
#define text "main"
using namespace std;

void input()
{
    sync;
    freopen(text".inp","r",stdin);
    freopen(text".out","w",stdout);
}

bool check(string& s)
{
    int i=0,f=s.size()-1;
    while (i<f)
    {
        if (s[i]!=s[f])
        {
            return false;
        }
        i++;
        f--;
    }
    return true;
}

int longestPalindromeSubstring(const string& s) {
    int n = s.length();
    if (n == 0) return 0;

    vector<vector<bool>> dp(n, vector<bool>(n, false));
    int maxLength = 1;
    for (int i = 0; i < n; i++) {
        dp[i][i] = true;
    }

    int start = 0;
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == s[i + 1]) {
            dp[i][i + 1] = true;
            start = i;
            maxLength = 2;
        }
    }
    for (int length = 3; length <= n; length++) {
        for (int i = 0; i < n - length + 1; i++) {
            int j = i + length - 1;
            if (s[i] == s[j] && dp[i + 1][j - 1]) {
                dp[i][j] = true;

                if (length > maxLength) {
                    start = i;
                    maxLength = length;
                }
            }
        }
    }

    return maxLength;
}

int main()
{
    input();
    string s; cin>>s;
    // for (int i=0;i<s.size()-1;i++)
    // {
    //     for (int f=i+1;f<s.size();f++)
    //     {

    //     }
    // }
    cout<<longestPalindromeSubstring(s);
    return 0;
}

