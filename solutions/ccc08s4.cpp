#pragma GCC optimize("O2")
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pb push_back
#define mp make_pair
using namespace std;
int n,c[4],ans;

void check(int inp) {
    if (inp<0 || inp>24) {return;}
    ans=max(ans,inp);
}

void solve(int cur,int nex,int ind) {
    if (ind==3) {
        check(cur+nex);
        check(cur-nex);
        check(cur*nex);
        if (nex!=0 && cur%nex==0) {check(cur/nex);}
        return;
    }
    solve(cur+nex,c[ind+1],ind+1);
    solve(cur*nex,c[ind+1],ind+1);
    solve(cur-nex,c[ind+1],ind+1);
    if (nex!=0 && cur%nex==0) {solve(cur/nex,c[ind+1],ind+1);}
    solve(cur,nex+c[ind+1],ind+1);
    solve(cur,nex-c[ind+1],ind+1);
    solve(cur,nex*c[ind+1],ind+1);
    if (c[ind+1]!=0 && nex%c[ind+1]==0) {solve(cur,nex/c[ind+1],ind+1);}
}

int main() {
    ios::sync_with_stdio(0);cin.tie(0);
    for (cin>>n;n>0;n--) {
        ans=0;
        for (int j=0;j<4;j++) {cin>>c[j];}
        sort(c,c+4);
        do {
            solve(c[0],c[1],1);
        } while (next_permutation(c,c+4));
        cout<<ans<<'\n';
    }
    return 0;
}
