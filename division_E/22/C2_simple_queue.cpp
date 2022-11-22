#include <iostream>
#include <vector>
#include <queue>
#include <sstream>

using namespace std;

int main(){
    queue<string> q;
    vector<string> v;

    while(true){
       string s;
       cin>>s;
       if(s.compare("push")==0){
            cin>>s;
            q.push(s);
            v.push_back("ok");
       } else if (s.compare("pop")==0){
           s = q.front();
           v.push_back(s);
           q.pop();

       } else if(s.compare("front")==0){
           v.push_back(q.front());

       } else if (s.compare("size")==0){
           std::ostringstream ostr;
           ostr << q.size();
           string res=ostr.str();
           v.push_back(res);

        }else if(s.compare("clear")==0){
            while(!q.empty()){
                q.pop();
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

