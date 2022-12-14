#include <iostream>

using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    int a[n+1][m+1];
    int dp[n+1][m+1];
    for(int i = 1; i<=n; ++i){
        for(int j=1; j<=m; ++j){
            cin>>a[i][j];
            dp[i][j]=0;
        }
    }
    dp[1][1]=1;
    for(int j = 2; j<=m; ++j){
        dp[1][j]=(a[1][j]==0)?0:dp[1][j-1];
    }
    for(int i =2; i<=n; ++i){
        dp[i][1]=(a[i][1]==0)?0:dp[i-1][1];
    }
    for(int i =2; i<=n; ++i){
        for(int j=2; j<=m; ++j){
            dp[i][j]=(a[i][j]==0)?0:(dp[i-1][j]+dp[i][j-1]);
        }
    }
    if(dp[n][m]==0){
        cout<<"Impossible\n";
    } else {
        cout<<dp[n][m]<<'\n';
    }
}
