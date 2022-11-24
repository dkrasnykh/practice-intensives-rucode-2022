#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    string s;
    vector<string> ans;
    while(getline(cin, s)){
        next_permutation(s.begin(), s.end());
        ans.push_back(s);
    }

    for(size_t i = 0; i<ans.size(); i++){
        cout<<ans[i]<<'\n';
    }
}
