#include <iostream>
#include <limits>

using namespace std;

bool check(int m, int k, int t[], int z[], int y[], int n){
    int cnt=0;
    for(int i = 0; i<n; i++){
        int part = (((m%(t[i]*z[i]+y[i]))/t[i])<  z[i])?(m%(t[i]*z[i]+y[i])/t[i]):z[i];
        cnt+=z[i]*(m/(t[i]*z[i]+y[i]))+part;
    }
    return cnt>=k;
}

int binsearch(int l, int r, int k, int t[], int z[], int y[], int n) {
    while (l < r) {
        int m = (l + r) / 2;
        if (check(m, k, t, z, y, n)) {
            r = m;
        } else {
            l = m + 1;
        }
    }
    return l;
}

int main(){
    int m, n;
    cin>>m>>n;
    int t[n];
    int z[n];
    int y[n];
    for(int i = 0; i<n; i++){
        cin>>t[i]>>z[i]>>y[i];
    }
    int r = std::numeric_limits<int>::max();
    int ans = binsearch(0, r, m, t, z,y, n);
    cout<<ans<<'\n';
    int cnt=m;
    for(int i = 0; i<n; i++){
        int part = ((ans%(t[i]*z[i]+y[i])/t[i])< z[i])?(ans%(t[i]*z[i]+y[i])/t[i]):z[i];
        int res = (z[i]*(ans/(t[i]*z[i]+y[i]))+part);
        cout<<((cnt<=res)?((cnt<0)?0:cnt):res)<<' ';
        cnt-=res;
    }
}
