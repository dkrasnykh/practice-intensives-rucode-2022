#include <iostream>
#include <vector>

using namespace std;

void divide(vector<int> &ans, int step, int n, int local){
    if(n==0){
        for(int i=0; i<step; ++i){
            cout<<ans[i]<<" ";
        }
        cout<<"\n";
        return;
    }
    for(int i = 1; i<=min(local, n); ++i){
        ans[step]=i;
        divide(ans, step+1, n-i, i);
    }
}

int main(){
    int n;
    cin>>n;
    vector<int> ans(n);
    divide(ans, 0, n, n);
}
