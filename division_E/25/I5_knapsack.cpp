#include <iostream>

using namespace std;

int main(){
    int s,n;
    cin>>s>>n;
    int w[n+1];
    for(int i = 1; i<=n; i++){
        cin>>w[i];
    }

    int dp[n+1][s+1];
    for(int i = 0; i<=n; ++i){
        for(int j=0; j<=s; ++j){
            dp[i][j]=0;
        }
    }
    dp[0][0]=1;

    for(int i = 1; i<=n; ++i){
        for(int j=0; j<=s; ++j){
            if(w[i]<=j){
                dp[i][j]=dp[i-1][j]||dp[i-1][j-w[i]];
            } else {
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    for(int w1=s; w1>=0; w1--){
        if(dp[n][w1]==1){
            cout<<w1<<'\n';
            return 0;
        }
    }
}
