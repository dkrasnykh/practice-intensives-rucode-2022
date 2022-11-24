#include <iostream>
#include <vector>

using namespace std;

int binsearch(int l, int r, int n, int[] a) {
    while (l < r) {
        int m = (r + l) / 2;
        if (a[m] >= n) {
            r = m;
        } else {
            l = m + 1;
        }
    }
    if (l == a.length-1 && a[l] != n) {
        return l + 1;
    }
    return l;
}

int binsearch1(int l, int r, int n, int[] a) {
    while (l < r) {
        int m = (r + l) / 2;
        if (a[m] > n) {
            r = m;
        } else {
            l = m + 1;
        }
    }
    if(l==a.length-1 && n>=a[l]){
        return l+1;
    }
    return l;
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i = 0; i<n; i++){
        cin>>a[i];
    }

    //сортировать массив а

    //vector<string> v=
}
