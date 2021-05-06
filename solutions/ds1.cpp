#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;
const ull MAXN=100002;
ull n,m,a[MAXN];

struct BIT {
    ull fw[MAXN],sz;
    void update(ull p,ull v) {
        for (;p<=sz;p+=p&-p) {fw[p]+=v;}
    }
    ull query(ull p) {
        ull s=0;
        for (;p>0;p-=p&-p) {s+=fw[p];}
        return s;
    }
}tree,freq;

int main() {
    cin>>n>>m;
    tree.sz=n;freq.sz=MAXN;
    for (ull i=1;i<=n;i++) {
        cin>>a[i];
        tree.update(i,a[i]);
        freq.update(a[i],1);
    }
    char op;
    for (ull i=1,x,y;i<=m;i++) {
        cin>>op;
        if (op=='C') {
            cin>>x>>y;
            tree.update(x,y-a[x]);
            freq.update(a[x],-1);
            freq.update(y,1);
            a[x]=y;
        } else if (op=='S') {
            cin>>x>>y;
            cout<<tree.query(y)-tree.query(x-1)<<'\n';
        } else {
            cin>>x;
            cout<<freq.query(x)<<'\n';
        }
    }
    return 0;
}
