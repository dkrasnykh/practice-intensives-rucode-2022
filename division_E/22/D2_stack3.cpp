#include <iostream>
#include <vector>
#include <stack>
#include <sstream>

using namespace std;

int main(){
    int q;
    cin>>q;
    stack<int> st;
    stack<int> smax;
    vector<int> v;
    for(int i = 0; i<q; i++){
        string s;
        cin>>s;
        if(s.compare("push")==0){
            int p;
            cin>>p;
            int cmax;
            if(!smax.empty()){
                cmax = (smax.top()>p)?smax.top():p;
            } else {
                cmax=p;
            }
            st.push(p);
            smax.push(cmax);
        } else if (s.compare("pop")==0){
            if(st.size()>0){
                st.pop();
                smax.pop();
            }
        } else if (s.compare("max")==0){
            if(smax.size()>0){
                v.push_back(smax.top());
            }
        }
    }
    for(size_t i = 0; i<v.size(); i++){
        cout<<v[i]<<'\n';
    }
}

