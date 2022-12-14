#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int n;
    cin>>n;
    unsigned long long dp[n+1];
    dp[1]=3;
    if(n==1){
        cout<<dp[1]<<'\n';
        return 0;
    }
    dp[2]=8;
    for(int i =3; i<=n; i++){
        dp[i]=2*(dp[i-1]+dp[i-2]);
    }
    cout<<dp[n]<<'\n';
}
