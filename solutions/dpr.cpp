#pragma optimize GCC("O2")
#pragma GCC target("avx,avx2,fma") 
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pb push_back
#define mp make_pair
using namespace std;
ll n,k,mod=1e9+7;

struct Matrix {
    vector<vector<ll>> a;
    void create() {
        a.resize(n+1);
        for (int i=0;i<=n;i++) {a[i].resize(n+1);}
    }
    Matrix operator ^(Matrix b) {
        Matrix c;
        c.create();
        for (int i=0;i<n;i++) {
            for (int j=0;j<n;j++) {
                for (int k=0;k<n;k++) {
                    c.a[i][j]=(c.a[i][j]+(a[i][k]*b.a[k][j]))%mod;
                }
            }
        }
        return c;
    }
}ma,mb;

void binexpo(ll exp) {
    while (exp>0) {
        if (exp&1) ma=ma^mb;
        mb=mb^mb;
        exp>>=1;
    }
}

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>k;
    ma.create();mb.create();
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            cin>>ma.a[i][j];
            mb.a[i][j]=ma.a[i][j];
        }
    }
    binexpo(k-1);
    ll o=0;
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            o=(o+ma.a[i][j])%mod;
        }
    }
    cout<<o<<'\n';
    return 0;
}
