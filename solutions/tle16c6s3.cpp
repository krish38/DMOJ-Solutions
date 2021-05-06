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
const int MM=2002,mod=1e9+7,INF=0x3f3f3f3f;
ll n,psa[MM],dp[MM][MM][2],o;
pair<int,int> a[MM];

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++) {cin>>a[i].first>>a[i].second;}
    sort(a+1,a+n+1);
    for (int i=1;i<=n;i++) {
        psa[i]=psa[i-1]+a[i].second;
        if (a[i].first==0) {dp[i][i][0]=dp[i][i][1]=a[i].second;}
    }
    for(int i=1; i<n; i++){
        for(int j=1; j+i<=n; j++){
            int r = j+i;
            if(dp[j+1][r][0] >= a[j+1].first - a[j].first)
                dp[j][r][0]=max(dp[j][r][0], dp[j+1][r][0]+a[j].second-(a[j+1].first-a[j].first));
            if(dp[j+1][r][1] >= a[r].first - a[j].first)
                dp[j][r][0]=max(dp[j][r][0], dp[j+1][r][1]+a[j].second-(a[r].first-a[j].first));
            if(dp[j][r-1][1] >= a[r].first - a[r-1].first)
                dp[j][r][1]=max(dp[j][r][1], dp[j][r-1][1]+a[r].second-(a[r].first-a[r-1].first));
            if(dp[j][r-1][0] >= a[r].first - a[j].first)
                dp[j][r][1]=max(dp[j][r][1], dp[j][r-1][0]+a[r].second-(a[r].first-a[j].first));
        }
    }
    for (int i=1;i<=n;i++) {for (int j=i;j<=n;j++) {if (dp[i][j][0]>0 || dp[i][j][1]>0) {o=max(o,psa[j]-psa[i-1]);}}}
    cout<<o<<'\n';
    return 0;
}
