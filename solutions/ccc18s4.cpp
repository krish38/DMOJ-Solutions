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
const int MM=1e9+2,mod=1e9+7,INF=0x3f3f3f3f;
int n; unordered_map<int,ll> dp;
ll f(int w) {
    if (w<=2) {return 1;}
    if (dp.count(w)) {return dp[w];}
    ll a=sqrt(w),b=0;
    for (int k=2;k<=a;k++) {b+=f(w/k);}
    ll c=a;
    for (int i=a;i>=1;i--) {b+=(w/i-c)*f(i);c=w/i;}
    return dp[w]=b;
}

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    cout<<f(n)<<'\n';
    return 0;
}
