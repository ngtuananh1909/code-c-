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

int main()
{
    input();
    int n; cin>>n;
    vector<int> a(n+1);
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    
    return 0;
}

