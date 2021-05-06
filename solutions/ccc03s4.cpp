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
using namespace std;
inline ll gcd(ll a, ll b) {return b==0?a:gcd(b,a%b);}
inline ll lcm(ll a, ll b) {return a*b/gcd(a,b);}
char _;
const int MM=1e5+2,mod=1e9+7,INF=0x3f3f3f3f;
int n,c=0;

int lcp(string a,string b) {
    int cc=0;
    for (int i=0;i<min(a.size(),b.size());i++) {
        if (a[i]!=b[i]) {break;}
        cc++;
    }
    return cc;
}

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for (int i=0;i<n;i++) {
        string s;
        cin>>s;
        int sz=s.size();
        string suf[sz];
        for (int i=0;i<sz;i++) {
            suf[i]=(string)s;
            s=s.substr(1,s.size());
        }
        sort(suf,suf+sz);
        c=suf[0].size();
        for (int i=0;i<sz-1;i++) {c+=suf[i+1].size()-lcp(suf[i],suf[i+1]);}
        cout<<c+1<<'\n';
    }
    
    return 0;
}
