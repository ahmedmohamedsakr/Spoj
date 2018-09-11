#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e4+5,M=1e6+5,OO=0x3f3f3f3f;
int n,m,u,v,in[N];
vector<int>adj[N];
vector<int>topo;
void BFS()
{
    priority_queue<int,vector<int>,greater<int>>pq;
    for(int i=1; i<=n; ++i)if(!in[i])pq.push(i);
    while(!pq.empty())
    {
        int u=pq.top();
        pq.pop();
        topo.push_back(u);
        for(auto it:adj[u])if(!--in[it])pq.push(it);
    }
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0; i<m; ++i)
    {
        scanf("%d%d",&u,&v);
        adj[u].push_back(v);
        in[v]++;
    }
    BFS();
    if(topo.size()!=n)printf("Sandro fails.\n");
    else for(int i=0; i<topo.size(); ++i)printf("%d%c",topo[i]," \n"[i==n-1]);
    return 0;
}
