#include <bits/stdc++.h>
#define sync ios_base::sync_with_stdio(false); cin.tie(0);cout.tie(0);
#define text "coprime"
using namespace std;

void input()
{
    sync;
    freopen(text".inp","r",stdin);
    freopen(text".out","w",stdout);
}

bool uocchung(int a,int b)
{
    while (a!=0)
    {
        int tmp=b%a;
        b=a;
        a=tmp;
    }
    return b==1;
}

int main()
{
    input();
    int n; cin>>n;
    vector<int> a(n+1);
    vector<bool> check(n+1,false);
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        if (i!=1)
        {
            check[i-1]=uocchung(a[i],a[i-1]);
        }
    }
    int dem=0,res=0;
    for (int i=1;i<=n;i++)
    {
        if (check[i]) dem++;
        else if (!check[i]) {
            dem++;
            if (dem==1)
            {
                dem=0;
                continue;
            }
            res=max(dem,res);
            dem=0;
        }
    }
    cout<<max(res,dem);
    return 0;
}

