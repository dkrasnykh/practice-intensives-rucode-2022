#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <numeric>
#include <algorithm>
#include <string>
#include <sstream>

std::vector<int> ans;
std::multiset<std::vector<int>> ans2;
std::map<int, int> used;
void generate(int total, std::vector<int>& vfsums, int k, int last) {
    int sum = std::accumulate(ans.begin(), ans.end(), 0);
    if (sum>total) {
        return;
    }
    else if (sum == total) {
        std::vector<int> tmp(ans);
        std::reverse(tmp.begin(), tmp.end());
        ans2.insert(tmp);
        return;
    }

    for (size_t i = 0; i != vfsums.size(); ++i) {
        if (used[vfsums[i]]<k && vfsums[i]<=last) {
        //if (used[vfsums[i]] < k) {
            ++used[vfsums[i]];
            ans.push_back(vfsums[i]);

            generate(total, vfsums, k, vfsums[i]);
            //generate(total, vfsums, k);

            int j = ans.back();
            if (used[j]>0) {
                --used[j];
            }
            ans.pop_back();
        }
    }
}

int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> vfsums;
    vfsums.push_back(1);
    vfsums.push_back(2);
    for (size_t i = 2; i < 11; ++i) {
        vfsums.push_back(vfsums[i - 1] + vfsums[i - 2]);
    }
    generate(n, vfsums, k, vfsums[vfsums.size()-1]);
    //generate(n, vfsums, k);
    for (const auto& e : ans2) {
        for (size_t i = 0; i != e.size(); ++i) {
            if (i > 0) {
                std::cout << '+';
            }
            std::cout << e[i];
        }
        std::cout << '\n';
    }
}
