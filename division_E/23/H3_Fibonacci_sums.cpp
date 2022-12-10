#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <numeric>
#include <algorithm>

std::map<int, int> mmap;

int fibn(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    auto fn1 = mmap.find(n - 1);
    auto fn2 = mmap.find(n - 2);
    if (fn1 == mmap.end() && fn2 == mmap.end()) {
        mmap.insert({ n, fibn(n - 1) + fibn(n - 2) });
        return mmap[n];
    }
    else if (fn1 == mmap.end()) {
        mmap.insert({ n - 1, fibn(n - 1) });
        return mmap[n - 1] + fn2->second;
    }
    else if (fn2 == mmap.end()) {
        mmap.insert({ n - 2, fibn(n - 2) });
        return fn1->second + mmap[n - 2];
    }
    else {
        return fn1->second + fn2->second;
    }
}

std::vector<int> ans;
std::vector<std::multiset<int>> ans2;
std::map<int, int> used;
void generate(int total, std::vector<int>& vfsums, int k) {
    int sum = std::accumulate(ans.begin(), ans.end(), 0);
    if (sum>total) {
        return;
    }
    else if (sum == total) {
        std::multiset<int> tmp;
        for (size_t i = 0; i != ans.size(); ++i) {
            tmp.insert( ans[i] );
        }
        if (std::find(ans2.begin(), ans2.end(), tmp)==ans2.end()) {
            for (size_t i = 0; i != ans.size(); ++i) {
                if (i > 0) {
                    std::cout << "+";
                }
                std::cout << ans[i];
            }
            std::cout << '\n';
            ans2.push_back(tmp);
        }
        return;
    }

    for (size_t i = 0; i != vfsums.size(); ++i) {
        //if (used[vfsums[i]]<k && vfsums[i]<=last) {
        if (used[vfsums[i]] < k) {
            ++used[vfsums[i]];
            ans.push_back(vfsums[i]);

            //generate(total, vfsums, k, vfsums[i]);
            generate(total, vfsums, k);

            int j = ans.back();
            if (used[j]>0) {
                --used[j];
            }
            ans.pop_back();
        }
    }
}

int main() {
    //Первая строка ввода содержит число n (1 ≤ n ≤ 100).
    //Вторая строка ввода содержит число k (1 ≤ k ≤ 20).
    int n, k;
    std::cin >> n >> k;
    //n=5 -> 8
    //n=6 -> 13
    //11 -> 144
    fibn(11);
    std::vector<int> vfsums;
    for (const auto& [number, fsum] : mmap) {

        vfsums.push_back(fsum);
    }
    //generate(n, vfsums, k, vfsums[vfsums.size()-1]);
    generate(n, vfsums, k);
}
