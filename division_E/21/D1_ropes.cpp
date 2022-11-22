#include <iostream>

using namespace std;

bool check(int m, int k, int rope[], int n){
    int cnt=0;
    for(int i = 0; i<n; i++){
        cnt+=rope[i]/m;
    }
    return (k<=cnt);
}

int binsearch(int l, int r, int k, int rope[], int n) {
    while (l < r) {
        int m = (l + r + 1) / 2;
        if (check(m, k, rope, n)) {
            l = m;
        } else {
            r = m - 1;
        }
    }
    return l;
}

int main(){
    int n, k;
    cin>>n>>k;
    int rope[n];
    int maxl=0;
    for(int i = 0; i<n; i++){
        cin>>rope[i];
        maxl=(rope[i]>maxl)?rope[i]:maxl;
    }
    cout<<binsearch(0, maxl, k, rope, n)<<'\n';
}
