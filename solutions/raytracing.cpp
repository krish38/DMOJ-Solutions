#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;
int n=0,q=0,i=0,j=0,a=0,b=0,h[8195];

int query(int w, int x, int y, int z) {
    int out=0;
    for(int ind=w;ind<=x;ind++){if (h[ind]>=y && h[ind]<=z) {out++;}}
    return out;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    cin>>n;
    for (int ind=0;ind<n;ind++) {
        cin>>h[ind];
    }
    cin>>q;
    for (int ind=0,k;ind<q;ind++) {
        cin>>k;
        if (k==1) {
            cin>>i>>j>>a>>b;
            cout << query(i,j,a,b) << '\n';
        } else {
            cin>>i>>j;
            h[i]=j;
        }
    }
    return 0;
}
