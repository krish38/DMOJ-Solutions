#pragma GCC optimize("O2")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
//YOU THOUGHT THIS WAS REGULAR C++ SYNTAX BUT IT WAS I DIO
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
using namespace std;
inline ll gcd(ll a, ll b) {return b==0?a:gcd(b,a%b);}
inline ll lcm(ll a, ll b) {return a*b/gcd(a,b);}
char _;
const int MM=1002,mod=1e9+7,INF=0x3f3f3f3f;
int m,n,a[MM][MM];
bool visited[1000003];
string o="no";

void dfs(int x,int y) {
    if (x==m-1 && y==n-1) {o="yes";return;}
    int u=a[x][y];
    if (visited[u]) {return;}
    visited[u]=true;
    for (int i=1;i<=min(max(m,n),(int)sqrt(u));i++) {
        if (u%i==0) {
            if (i<=m && (u/i)<=n) {dfs(i-1,(u/i)-1);}
            if (i<=n && (u/i)<=m) {dfs((u/i)-1,i-1);}
        }
    }
}

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>m>>n;
    for (int i=0;i<m;i++) {
        for (int j=0;j<n;j++) {
            cin>>a[i][j];
        }
    }
    for (int i=0;i<1000003;i++) {visited[i]=false;}
    dfs(0,0);
    cout<<o<<'\n';
    return 0;
}
