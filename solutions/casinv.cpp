#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

const int MAXN=1e6+2;
int n,a[MAXN],b[MAXN];
ll out=0,o=0;

int main() {
    cin>>n;
    for (int i=0;i<n;i++) {cin>>a[i];}
    for (int i=0;i<n;i++) {cin>>b[i];}
    sort(a,a+n);
    sort(b,b+n);
    if (a[n-1]!=b[n-1]) {cout<<-1<<'\n';}
    else {
        for (int i=0,r=0;i<n;i++) {
            while (r<n && b[r]<=a[i]) {out+=b[r];r++;}
            o += out + 1LL*(n-r)*a[i];
        }
        cout<<o<<'\n';
    }
    return 0;
}
