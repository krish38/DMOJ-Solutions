#include <bits/stdc++.h>
using namespace std;
int n=0,q=0, a[50003], logt[50003], stmin[16][50003], stmax[16][50003];
pair<int,int> queries[200003];

int main() {
    cin>>n>>q;
    for (int i=0;i<n;i++) {
        cin>>a[i];
    }
    
    for (int i=0;i<q;i++) {
        cin>>queries[i].first>>queries[i].second;
    }

    logt[0]=0;logt[1]=0;
    for (int i=2;i<=n;i++) {logt[i] = logt[i/2]+1;}
    for (int i=0;i<n;i++) {
        stmin[0][i] = a[i];
        stmax[0][i] = a[i];
    }
    for (int r=1;r<=logt[n]; r++) {
        for (int i=0;i+(1<<r)<=n;i++) {
            stmin[r][i] = min(stmin[r-1][i], stmin[r-1][i+(1<<(r-1))]);
            stmax[r][i] = max(stmax[r-1][i], stmax[r-1][i+(1<<(r-1))]);
        }
    }

    int l=0,r=0,logval=0;
    for (int i=0;i<q;i++) {
        l=queries[i].first-1;r=queries[i].second;
        logval = logt[r-l];
        cout<<max(stmax[logval][l], stmax[logval][r-(1<<logval)])-min(stmin[logval][l], stmin[logval][r-(1<<logval)]) << '\n';
    }
    return 0;
}
