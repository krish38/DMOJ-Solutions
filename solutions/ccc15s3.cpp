#pragma GCC optimize("O2")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
//YOU THOUGHT THIS WAS REGULAR C++ SYNTAX BUT IT WAS I DIO
using namespace std;
inline ll gcd(ll a, ll b) {return b==0?a:gcd(b,a%b);}
inline ll lcm(ll a, ll b) {return a*b/gcd(a,b);}
char _;
const int MM=1e5+5,mod=1e9+7,INF=0x3f3f3f3f;
int g,p,x,y;
bitset<100005> a;

int main() {
    a.flip();
    cin>>g>>p;
    for (int i=0;i<p;i++) {
        cin>>x;
        y=a._Find_next(g-x);
        if (y>g) {cout<<i<<'\n';return 0;}
        a[y]=0;
        //cout<<i<<' '<<x<<' '<<y<<'\n';
    }
    cout<<p<<'\n';
    
    return 0;
}
