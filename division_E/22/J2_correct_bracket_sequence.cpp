#include <iostream>
#include <stack>

using namespace std;

int main(){
    string s;
    cin>>s;
    stack<char> s1;
    for(int i = 0; i<s.length(); ++i){
        if(s[i]=='{'){
            s1.push('{');
        } else if (s[i]=='[') {
            s1.push('[');
        } else if (s[i]=='(') {
            s1.push('(');
        } else if (s[i]=='}') {
            if(s1.size()>0 && s1.top()=='{'){
                s1.pop();
            } else {
                cout<<"no";
                return 0;
            }
        } else if (s[i]==']') {
            if(s1.size()>0 && s1.top()=='['){
                s1.pop();
            } else {
                cout<<"no";
                return 0;
            }
        } else if (s[i]==')') {
            if(s1.size()>0 && s1.top()=='('){
                s1.pop();
            } else {
                cout<<"no";
                return 0;
            }
        }
    }
    cout<<((s1.size()==0)?"yes":"no");
}
