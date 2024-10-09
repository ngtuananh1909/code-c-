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

bool pali(int& n)
{
    string s=to_string(n);
    string test=string(s.rbegin(),s.rend());
    return test==s;
}

set<int> count(int& n)
{
    set<int> save;
    while (n%2==0)
    {
        save.insert(2);
        n/=2;
    }
    for (int i=3;i*i<=n;i+=2)
    {
        while(n%i==0)
        {
            save.insert(i);
            n/=i;
        }
    }
    if (n>2) save.insert(n);
    return save;
}

int main()
{
    input();
    int a,b,res=0; cin>>a>>b;
    for (int i=66;i<=b;i++)
    {
        if (pali(i))
        {
            set<int> tmp=count(i);
            if (tmp.size()>=3) res++;
        }
    }
    cout<<res;
    return 0;
}

