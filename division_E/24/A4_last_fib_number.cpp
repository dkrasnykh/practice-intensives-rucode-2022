#include <iostream>

using namespace std;

int main(){
    int n;
    cin>>n;
    unsigned long long f0=1;
    unsigned long long f1=1;
    unsigned long long fN=1;
    for(int i = 2; i<=n; i++){
        fN=(f1%100+f0%100)%100;
        f0=f1;
        f1=fN;
    }
    cout<<fN%10<<'\n';
}
