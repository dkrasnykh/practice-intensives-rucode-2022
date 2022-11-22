#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main(){
    deque<int> q;
    int k;
    cin>>k;
    vector<int> ans;
    for(int i=0; i<k; ++i){
        string s;
        cin>>s;
        int n;
        if(s=="+"){
            cin>>n;
            q.push_back(n);
        } else if (s=="*"){
            cin>>n;
            int d = (q.size()%2>0?q.size()/2+1:q.size()/2);
            q.insert(q.begin()+d, n);
        } else if (s=="-"){
            ans.push_back(q.front());
            q.pop_front();
        }
    }
    for(size_t i=0; i<ans.size(); ++i){
        cout<<ans[i]<<'\n';
    }
}
