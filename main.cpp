#include <bits/stdc++.h>
#define test "main"
#define endl '\n'
#define PRO_NHI_PHONG_TIN int main()
#define sync ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
const int MAXN = 1e5 + 5;
void input()
{
    sync;
    freopen(test".inp","r",stdin);
    freopen(test".out","w",stdout);
}

int n,k; 
vector<int> tree(4*MAXN);
vector<int> a(MAXN);

void build(int idx,int l,int r)
{
    if (l==r)
    {
        tree[idx]=a[l];
        return ;
    }
    int mid=l+r>>1;
    build(idx*2,l,mid);
    build(idx*2+1,mid+1,r);
    tree[idx]=min(tree[idx*2],tree[idx*2+1]);
    return ;
}

int get(int idx,int l,int r,int u,int v)
{
    if (u>r || v<l) return INT_MAX;
    else if (u<=l && v>=r) return tree[idx];
    int mid =l+r>>1;
    return min(get(idx*2,l,mid,u,v),get(idx*2+1,mid+1,r,u,v));
}

PRO_NHI_PHONG_TIN
{
    input();
    cin>>n>>k;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    build(1,1,n);
    for (int i=k;i<=n;i++)
    {
        int u=i-k+1;
        int v=i;
        cout<<get(1,1,n,u,v)<<endl;
    }
    return 0;
}