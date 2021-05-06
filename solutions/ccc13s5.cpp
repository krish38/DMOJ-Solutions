#include <bits/stdc++.h>
using namespace std;

int main() {
  int n=0;
  cin>>n;
  
  int cost=0;
  while(n>1) {
    double r = sqrt(n)+1;
    double f = 2;
    while ((f<=r) && (fmod(n,f)!=0)) {
      f+=1;
    }

    if ((f<n) && (fmod(n,f) == 0)) {
      double x = n/f;
      n-=x;
      cost+=n/x;
    } else {
      n-=1;
      cost+=n;
    }
  }
  cout << cost << '\n';
}
