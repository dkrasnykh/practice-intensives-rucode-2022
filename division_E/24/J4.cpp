#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n+1];
    a[0]=0;
    for(int i = 1; i<=n; i++){
        cin>>a[i];
    }
    sort(a, a+n+1);
    int free[n+1];
    for(int i = 0; i<=n; i++){
        free[i]=10001;
    }
    int busy[n+1];
    busy[0]=0;
    busy[1]=0;
    busy[2]=a[2]-a[1];
    for(int i =3; i<n; i++){
        busy[i]=min(busy[i-1]+a[i]-a[i-1], free[i-1]+a[i]-a[i-1]);
        free[i]=busy[i-1];
    }
    int ans = a[n]-a[n-1]+min(busy[n-1], free[n-1]);
    cout<<ans;
}
