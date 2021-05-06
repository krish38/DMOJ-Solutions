#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN=100002;
ll n,dp[MAXN],last[26],mod=10007;
string s;

int main() {
  cin>>s;
  n=s.size();
  for (int i=1;i<=n;i++) {
    int c= s[i-1]-'a';
    if (last[c]==0) {dp[i]=(2*dp[i-1]+1)%mod;}
    else {dp[i]=(2*dp[i-1]-dp[last[c]-1]+mod)%mod;}
    last[c]=i;
  }
  cout<<dp[n]<<'\n';
  return 0;
}
