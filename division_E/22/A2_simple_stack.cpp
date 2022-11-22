#include <iostream>
#include <vector>
#include <stack>
#include <sstream>

using namespace std;

int main(){
    stack<string> st;
    vector<string> v;
    while(true){
       string s, q;
       cin>>s;
       if(s.compare("push")==0){
            //int n;
            cin>>s;
            st.push(s);
            v.push_back("ok");
       } else if (s.compare("pop")==0){
           q = st.top();
           v.push_back(q);
           st.pop();

       } else if(s.compare("back")==0){
           v.push_back(st.top());

       } else if (s.compare("size")==0){
           std::ostringstream ostr;
           ostr << st.size();
           string res=ostr.str();
           v.push_back(res);

        }else if(s.compare("clear")==0){
            while(st.size()>0){
                st.pop();
            }
            v.push_back("ok");
       } else if(s.compare("exit")==0){
            v.push_back("bye");
            break;
       }
    }

    for(size_t i = 0; i<v.size(); i++){
        cout<<v[i]<<'\n';
    }
}
