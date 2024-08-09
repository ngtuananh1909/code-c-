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

int n,m; 

vector<int> x={-1,1,0,0};
vector<int> y={0,0,1,-1};
vector <vector<bool>> check_idx(2500+1,vector<bool> (2500+1,false));

bool check(int i,int f,int i_new,int f_new,int n,int m,vector<vector<int>>& a,vector<vector<bool>>& used)
{
    return i_new>0 && f_new>0 && i_new<=n && f_new<=m && !used[i_new][f_new] && a[i][f]==a[i_new][f_new];
}

void bfs (int i,int f,vector<vector<int>>& a,vector<vector<bool>>& used)
{

    queue<pair<int,int>> pq;
    pq.push({i,f});
    used[i][f]=true;
    while (!pq.empty())
    {
        int u=pq.front().first,v=pq.front().second;
        pq.pop();
        for (int z=0;z<4;z++)
        {
            int x_new=u+x[z];
            int y_new=v+y[z];
            if (check(u,v,x_new,y_new,n,m,a,used))
            {
                used[x_new][y_new]=true;
                pq.push({x_new,y_new});
            }
        }
    }
    return ;
}


PRO_NHI_PHONG_TIN
{
    input();
    cin>>n>>m;
    vector<vector<int>> a(n+1,vector<int>(m+1));
    for (int i=1;i<=n;i++)
    {
        for (int f=1;f<=m;f++)
        {
            cin>>a[i][f];
        }
    }
    int res=0;
    for (int i=1;i<=n;i++)
    {
        for (int f=1;f<=m;f++)
        {
            if (!check_idx[i][f])
            {
                bfs(i,f,a,check_idx);
                res++;
            }
        }
    }
    cout<<res;
    return 0;
}
