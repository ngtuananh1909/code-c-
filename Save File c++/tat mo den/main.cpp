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
    int n,q; cin>>n>>q;
    vector<int> check(n+1,0);
    while (q--)
    {
        int x,y; cin>>x>>y;
        for (int i=x;i<=y;i++)
        {
            check[i]=abs(check[i]-1);
        }
    }
    for (int i=1;i<=n;i++) cout<<check[i]<<" ";
    return 0;
}
