#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

vector<char> bstr;

string generateBinaryString(int length){
    for(size_t i=0; i<bstr.size(); i++){
        cout<<bstr[i];
    }
    cout<<'\n';


    if(bstr.size()==length){
        //cout<<s<<'\n';
        //return s;
        for(size_t i=0; i<bstr.size(); i++){
            cout<<bstr[i];
        }
        cout<<'\n';
    } else {
        bstr.push_back('0');
        generateBinaryString(length);
        //bstr.pop_back();
        bstr.push_back('1');
        generateBinaryString(length);
        //bstr.push_back('1');
    }
}

int main(){
    /*
    string s = "111";
    s=s.substr(0, s.length()-1);
    cout<<s;
    */
    int n;
    cin>>n;
    generateBinaryString(n);


    //generateBinaryString("1", n);

}
