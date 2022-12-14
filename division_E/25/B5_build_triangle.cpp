#include <iostream>

using namespace std;

int main(){
    int n;
    cin>>n;
    int dp[n+1][n+1];
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=i; j++){
            if(j==1 || j==i){
                dp[i][j]=1;
            } else {
                dp[i][j]=dp[i-1][j]+dp[i-1][j-1];
            }
        }
    }
    for(int i=1; i<=n; ++i){
        for(int j=1; j<i; j++){
                cout<<dp[i][j]<<' ';
        }
        cout<<dp[i][i]<<'\n';
    }
}
