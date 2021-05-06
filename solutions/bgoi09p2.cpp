#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MM=100002;
ll n,cnt,x,p[MM];

ll find(ll d) {
    if (d!=p[d]) p[d]=find(p[d]);
    return p[d];
}

int main() {
    for (int cs=0;cs<2;cs++) {
        cin>>n;
        for (int i=0;i<MM;i++) p[i]=0;
        for (int i=1;i<=n;i++) p[i]=i;
        cnt=0;
        for (int i=1;i<=n;i++) {
            cin>>x;
            int fi=find(i),fx=find(x);
            if (fi!=fx) {cnt++;p[fx]=fi;}
        }
        cout<<n-cnt<<' ';
    }
    return 0;
}
