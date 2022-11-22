#include <iostream>

using namespace std;

bool check(int m, int k, int stall[], int n){
    int cnt=1;
    int last = stall[0];
    for(int i = 1; i<n; i++){
      if(stall[i]-last>=m){
        cnt++;
        last=stall[i];
      }
    }
    return (k<=cnt);
}

int binsearch(int l, int r, int k, int stall[], int n) {
    while (l < r) {
        int m = (l + r + 1) / 2;
        if (check(m, k, stall, n)) {
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
    int stall[n];
    for(int i = 0; i<n; i++){
        cin>>stall[i];
    }
    cout<<binsearch(0, stall[n-1]-stall[0], k, stall, n)<<'\n';
}
