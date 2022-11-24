#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> v;
    for(int i = 0; i<n; i++){
        int value;
        cin>>value;
        v.push_back(value);
    }
    int i = (int)(v.size()-1);
    bool found=false;
    while(i>0){
        if(v[i-1]<v[i]){
            int j = (int)(v.size()-1);
            while(v[j]<v[i-1]){
                j--;
            }
            int tmp=v[i-1];
            v[i-1]=v[j];
            v[j]=tmp;

            int k = (int)(v.size()-1);
            for(j=i; j<i+(v.size()-i)/2; j++){
                int tmp = v[j];
                v[j]=v[k];
                v[k]=tmp;
                k--;
            }
            found=true;
            break;
        }
        i--;
    }
    if(!found){
        for(i = 0; i<v.size()/2; i++){
            int tmp = v[i];
            v[i] = v[(int)(v.size()-1-i)];
            v[(int)(v.size()-1-i)] = tmp;
        }
    }
    for(i = 0; i<v.size(); i++){
        cout<<v[i]<<' ';
    }
}
