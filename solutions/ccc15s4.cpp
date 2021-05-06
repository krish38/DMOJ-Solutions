#pragma GCC optimize("O2")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pb push_back
#define mp make_pair
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
using namespace std;
char _;
const int MM=1e4+2,mod=1e9+7,INF=123456789;
int k,n,m,dp[2002][202];

struct r {
    int b,t,h;
    r(int bb,int tt,int hh) {b=bb;t=tt;h=hh;}
};

vector<r> paths[MM];

void bfs(int u,int v, int dis,int dam) {
    if (dam>=k) {return;}
    if (u==v) {dp[u][dam]=min(dp[u][dam],dis);}
    if (dis<=dp[u][dam]) {dp[u][dam]=dis;}
    else {return;}
    for (auto i: paths[u]) {
        bfs(i.b,v,dis+i.t,dam+i.h);
    }
}

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>k>>n>>m;
    for (int i=0,a,b,c,d;i<m;i++) {
        cin>>a>>b>>c>>d;
        paths[a].pb(r(b,c,d));
        paths[b].pb(r(a,c,d));
    }
    int A,B;
    cin>>A>>B;

    for (int i=0;i<=n;i++) {
        for (int j=0;j<=k;j++) {
            dp[i][j]=INF;
        }
    }

    bfs(A,B,0,0);
    int o=INF;

    for (int i=0;i<=k;i++) {
        o=min(o,dp[B][i]);
    }
    if (o==INF) {cout<<-1;}
    else {cout<<o<<'\n';}
    return 0;
}
