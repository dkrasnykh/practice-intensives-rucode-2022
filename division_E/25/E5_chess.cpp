#include <iostream>

using namespace std;

int main(){
    int c, r;
    cin>>c>>r;
    long long dp[9][9];
    for(int i = 0; i<=8; ++i){
        for(int j=0; j<=8; ++j){
            dp[i][j]=0;
        }
    }
    dp[r][c]=1;
    for(int i = r+1; i<=8; ++i){
        for(int j=1; j<=8; ++j){
           if(i-1>0 && j-1>0){
                dp[i][j]+=dp[i-1][j-1];
           }
           if(i-1>0 && j+1<9){
                dp[i][j]+=dp[i-1][j+1];
           }
        }
    }
    long long ans=0;
    for(int i=1; i<=8; ++i){
        ans+=dp[8][i];
    }
    cout<<ans<<'\n';
}
