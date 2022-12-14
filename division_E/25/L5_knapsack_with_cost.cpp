#include <iostream>

using namespace std;

int main(){
    int n,s;
    cin>>n>>s;
    int w[n+1];
    int p[n+1];
    int inf=1000000000;
    for(int i = 1; i<=n; i++){
        cin>>w[i];
    }
    for(int i = 1; i<=n; i++){
        cin>>p[i];
    }

    int dp[n+1][s+1];
    for(int i = 0; i<=n; ++i){
        for(int j=0; j<=s; ++j){
            dp[i][j]=-inf;
        }
    }
    dp[0][0]=0;

    for(int i = 1; i<=n; ++i){
        for(int j=0; j<=s; ++j){
            if(w[i]<=j){
                dp[i][j]=max(dp[i-1][j], dp[i-1][j-w[i]]+p[i]);
            } else {
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    int ans=0;
    for(int i = 0; i<=s; i++){
        ans=max(ans, dp[n][i]);
    }
    cout<<ans<<'\n';
}
