#include <iostream>

using namespace std;

int main(){
    int n;
    cin>>n;
    int w[n+1];
    int s=0;
    for(int i = 1; i<=n; i++){
        cin>>w[i];
        s+=w[i];
    }
    if(s%2==1 || n==1){
        cout<<"NO\n";
        return 0;
    }
    s/=2;


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
    if(dp[n][s]==1){
        cout<<"YES\n";
    } else {
        cout<<"NO\n";
    }
}
