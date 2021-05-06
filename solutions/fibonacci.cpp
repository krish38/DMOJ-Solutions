#pragma GCC optimize("O2")
#pragma GCC target("avx,avx2,fma")
#include <iostream>
using namespace std;
unsigned long long n=0,mod=1000000007;

struct Matrix {
    unsigned long long a[2][2] = {{1,1},{1,0}};
    Matrix operator ^(Matrix b) {
        Matrix c;
        c.a[0][0]=((a[0][0]*b.a[0][0])+(a[0][1]*b.a[1][0]))%mod;
        c.a[0][1]=((a[0][0]*b.a[0][1])+(a[0][1]*b.a[1][1]))%mod;
        c.a[1][0]=((a[1][0]*b.a[0][0])+(a[1][1]*b.a[1][0]))%mod;
        c.a[1][1]=((a[1][0]*b.a[0][1])+(a[1][1]*b.a[1][1]))%mod;
        return c;
    }
} x,y;

void exp(unsigned long long n) {
    Matrix i;
    while (n>0) {
        if (n&1) x=x^i;
        i=i^i;
        n>>=1;
    }
}

int main() {
    cin>>n;exp(n-1);
    cout<<x.a[0][1]%mod<<'\n';
    return 0;
}
