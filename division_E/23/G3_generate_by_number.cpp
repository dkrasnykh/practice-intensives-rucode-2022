#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <algorithm>

int fact(int n) {
    int ans = 1;
    for (int i = 2; i <= n; ++i) {
        ans *= i;
    }
    return ans;
}

int main() {
    int n, k;
    std::cin >> n >> k;
    //std::cout << k / fact(n - 1) << '\n';
    std::vector<bool> used(n+1, false);

    int fn1 = fact(n - 1);
    int i = 1;

    while (k > 0) {
        if (k>1 && k%(fn1==0?1:fn1)==0) {

            int t = k / (fn1==0?1:fn1);
            int cnt = 0;

            for (int i = 1; i <= n; i++) {
                if (!used[i]) {
                    cnt++;
                    if (cnt == t) {
                        std::cout << i << ' ';
                        used[i] = true;
                        break;
                    }
                }
            }
            //used[k / fn1] = true;
            //std::cout << k / fn1 << ' ';
            for (size_t j = n; j >= 1; --j) {
                if (!used[j]) {
                    std::cout << j << ' ';
                    used[j] = true;
                }
            }
        }
        else {
            //int t = k / fn1 + 1;
            int t = (k % (fn1==0?1:fn1) == 0) ? (k / (fn1==0?1:fn1)): (k / (fn1==0?1:fn1) + 1);
            int cnt = 0;
            for (int i = 1; i <= n; i++) {
                if (!used[i]) {
                    cnt++;
                    if (cnt == t) {
                        std::cout <<i << ' ';
                        used[i] = true;
                        break;
                    }
                }
            }
        }
        k = k % fn1;
        fn1 = fn1 /((n - i)==0?1:(n-i));
        i++;
    }
    for (int i = 1; i <= n; ++i) {
        if (!used[i]) {
            std::cout << i << ' ';
        }
    }

}
