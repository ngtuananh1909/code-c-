#include <bits/stdc++.h>
#define test "main"
#define endl '\n'
#define PRO_NHI_PHONG_TIN int main()
#define sync ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

void input()
{
    sync;
    freopen(test".inp","r",stdin);
    freopen(test".out","w",stdout);
}

PRO_NHI_PHONG_TIN
{
    input();
    int n,m; cin>>n>>m;
    vector<vector<int>> a(n+1,vector<int>(m+1));
    for (int i=1;i<=n;i++)
    {
        for (int f=1;f<=m;f++)
        {
            cin>>a[i][f];
        }
    }
    
    return 0;
}
