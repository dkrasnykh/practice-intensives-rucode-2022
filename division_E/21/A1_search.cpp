#include <iostream>

using namespace std;

int binsearch(int l, int r, int k, int b[], int lenght){
    while(l<r){
        int m = (l+r)/2;
        if(b[m]>=k){
            r=m;
        } else {
            l=m+1;
        }
    }
    if(b[l]!=k){
        return -1;
    }
    return l;

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin>>n>>k;

    int a[n];
    int b[k];

    for(int i = 0; i<n; i++){
        cin>>a[i];
    }

    for(int i=0; i<k; i++){
        cin>>b[i];
    }

    for(int i = 0; i<k; i++){
        int p=binsearch(0, n-1, b[i], a, n-1);
        if(p==-1){
            cout<<"NO"<<'\n';
        } else {
            cout<<"YES"<<'\n';
        }
    }
}
