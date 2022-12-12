#include <vector>
#include <iostream>

std::vector<int> permutation;
int cnt = 0;

void next_permutation(bool chosen[], const int n, const int t) {
    if (cnt<t) {
        if (permutation.size() == n) {
            ++cnt;
            for (size_t i = 0; i < permutation.size(); ++i) {
                std::cout << permutation[i] << ' ';
            }
            std::cout << '\n';
        }
        else {
            for (int i = 1; i <= n; ++i) {
                if (chosen[i] || (i - 1 == permutation.size())) {
                    continue;
                }
                chosen[i] = true;
                permutation.push_back(i);
                next_permutation(chosen, n, t);
                chosen[i] = false;
                permutation.pop_back();
            }
        }
    }
}

int main() {
    int n, t;
    std::cin >> n >> t;
    bool chosen[n + 1];
    for (int i = 0; i <= n; i++) {
        chosen[i] = false;
    }
    next_permutation(chosen, n, t);
}
