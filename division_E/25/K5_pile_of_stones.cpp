#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

int ans, N;
vector<int> w;

void rec(int n, int sum1, int sum2){
    if(n==N){
        if(abs(sum1-sum2)<ans){
            ans=abs(sum1-sum2);
        }
        return;
    }
    rec(n+1, sum1+w[n], sum2);
    rec(n+1, sum1, sum2+w[n]);
}

int main(){
    ans=2000001;
    cin>>N;
    int c;
    for(int i=0; i<N; i++){
        cin>>c;
        w.push_back(c);
    }
    rec(0,0,0);
    cout<<ans<<'\n';
}
