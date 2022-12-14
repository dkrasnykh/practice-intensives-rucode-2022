#include <iostream>

using namespace std;

int main(){
    int n;
    cin>>n;
    long long a[n+2];
    a[0]=1;
    a[1]=1;
    if(n==1){
        cout<<a[1]<<'\n';
        return 0;
    }
    a[2]=a[1]+1;
    for(int i = 3; i<=n; i++){
        if(i%2==1){
            a[i+1]=a[(i+1)/2]+1;
            a[i]=a[i+1]+a[(i-2)/2];
            //cout<<"a["<<i<<"]="<<a[i]<<'\n';
            //cout<<"a["<<i+1<<"]="<<a[i+1]<<'\n';
        }
    }
    cout<<a[n]<<'\n';
}
