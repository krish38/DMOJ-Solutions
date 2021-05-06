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
const int MM=1e6+2,mod=1e9+7,INF=0x3f3f3f3f;
string s;
int n;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    for (int num=0;num<5;num++) {
        cin>>s;
        n=s.size();
        int pal[n+1][n+1]={0};
        for (int i=0;i<n;i++) {pal[i][i+1]=1;}

        for (int i=2;i<=n;i++) {
            for (int j=0;j+i<=n;j++) {
                int k=i+j;
                //cout<<i<<' '<<j<<' '<<k<<'\n';
                if (s[j]==s[k-1]) {pal[j][k]=pal[j+1][k-1]+2;}
                else {pal[j][k]=max(pal[j+1][k],pal[j][k-1]);}
            }
        }
        cout<<pal[0][n]<<'\n';
    }
    return 0;
}
