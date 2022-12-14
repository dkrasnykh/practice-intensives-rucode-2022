#include <iostream>

using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    unsigned long long dp[n+2][m+2];
    for(int i = 0; i<=n+1; ++i){
        for(int j=0; j<=m+1; ++j){
            dp[i][j]=0;
        }
    }
    dp[0][1]=1;
    for(int i=2; i<=n+1; ++i){
        for(int j=2; j<=m+1; ++j){
           dp[i][j]+=(dp[i-2][j-1]+dp[i-1][j-2]);
        }
    }
    cout<<dp[n+1][m+1]<<'\n';
}
