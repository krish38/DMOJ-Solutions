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
int a[8],b[8],o=0;

void c(int bl,int pa) {
    int d=min(a[bl], b[pa]);
    a[bl]-=d;b[pa]-=d;
    o+=d;
}

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>a[0]>>a[1]>>a[2]>>a[3]>>a[4]>>a[5]>>a[6]>>a[7];
    cin>>b[0]>>b[1]>>b[2]>>b[3]>>b[4]>>b[5]>>b[6]>>b[7];
    c(0,0);
    c(1,1);
    c(0,1);
    c(2,2);
    c(0,2);
    c(4,4);
    c(0,4);
    c(3,3);
    c(1,3);
    c(5,5);
    c(1,5);
    c(2,3);
    c(0,3);
    c(4,5);
    c(0,5);
    c(6,6);
    c(4,6);
    c(2,6);
    c(0,6);
    c(7,7);
    c(6,7);
    c(5,7);
    c(4,7);
    c(3,7);
    c(2,7);
    c(1,7);
    c(0,7);

    cout<<o<<'\n';
        
    return 0;
}
