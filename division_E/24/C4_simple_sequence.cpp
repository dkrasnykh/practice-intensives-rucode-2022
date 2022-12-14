#include <iostream>

using namespace std;

int main(){
    int n;
    cin>>n;
    unsigned long long a[n+1];
    a[0]=1;
    a[1]=1;
    for(int i = 2; i<=n; i++){
        if(i%2==0){
            a[i]=a[i/2]+a[i/2-1];
        } else {
            a[i]=a[(i-1)/2]-a[(i-1)/2-1];
        }
    }
    cout<<a[n]<<'\n';
}
