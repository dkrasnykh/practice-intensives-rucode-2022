#include <iostream>

using namespace std;

int main(){
    int n;
    cin>>n;
    long long dp[n+1];
    dp[0]=1;
    dp[1]=1;
    if(n==1){
        cout<<"1"<<'\n';
        return 0;
    }
    dp[2]=dp[0]+dp[1];
    for(int i = 3; i<=n; i++){
        dp[i] = dp[i-1]+dp[i-2]+dp[i-3];
    }
    cout<<dp[n]<<'\n';
}
