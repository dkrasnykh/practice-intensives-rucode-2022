#include <iostream>

using namespace std;

int main(){
    int n, m;
    cin>>n>>m;
    int dp[n+1][m+1];
    for(int i= 1; i<=m; ++i){
        dp[1][i]=1;
    }
    for(int i = 1; i<=n; ++i){
        dp[i][1]=1;
    }
    for(int i = 2; i<=n; ++i){
        for(int j = 2; j<=m; j++){
           dp[i][j]=dp[i][j-1]+dp[i-1][j];
        }
    }
    cout<<dp[n][m]<<'\n';
}
