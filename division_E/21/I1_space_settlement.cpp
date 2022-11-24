#include <iostream>
#include <stdio.h>

using namespace std;

bool check(unsigned long long m, unsigned long long  n, unsigned long long a, unsigned long long b, unsigned long long w, unsigned long long h){
    unsigned long long i1=h/(a+2*m);
    unsigned long long j1=w/(b+2*m);
    unsigned long long i2=h/(b+2*m);
    unsigned long long j2=w/(a+2*m);
    return (i1*j1>=n) || (i2*j2>=n);
}

unsigned long long binsearch(unsigned long long l, unsigned long long r, unsigned long long  n, unsigned long long a, unsigned long long b, unsigned long long w, unsigned long long h) {
    while (l < r) {
        unsigned long long m = (l + r + 1) / 2;
        if (check(m, n, a, b, w, h)) {
            l = m;
        } else {
            r = m - 1;
        }
    }
    return l;
}

int main(){
    unsigned long long  n, a, b, w, h;
    cin>>n>>a>>b>>w>>h;
    /*
    unsigned long long a1=(h-a*n);
    unsigned long long a2=(w-b*n);
    unsigned long long a3=(h-b*n);
    unsigned long long a4=(w-a*n);
    */
    unsigned long long cnt1=h/a;
    unsigned long long cnt2=n/(cnt1==0?1:cnt1);
    unsigned long long pers=w-cnt2*b;

    unsigned long long cnt3=w/b;
    unsigned long long cnt4=n/(cnt3==0?1:cnt3);
    unsigned long long pers2=h-cnt4*a;

    unsigned long long cnt5=h/b;
    unsigned long long cnt6=n/(cnt5==0?1:cnt5);
    unsigned long long pers3=w-cnt6*a;

    unsigned long long cnt7=w/a;
    unsigned long long cnt8=n/(cnt7==0?1:cnt7);
    unsigned long long pers4=h-cnt8*b;


    unsigned long long r=max(max(pers, pers2), max(pers3, pers4));

    cout<<binsearch(0, r, n, a, b, w, h);
}
