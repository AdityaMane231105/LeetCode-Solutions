#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

class Solution {
public:
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        unordered_map<int, long long> freq;
        multiset<pair<long long,int>> high, low;
        long long sumHigh = 0;
        vector<long long> ans;

        auto add = [&](int v) {
            long long f = freq[v]++;
            if (f > 0) {
                auto old = make_pair(f, v);
                if (high.count(old)) {
                    high.erase(high.find(old));
                    sumHigh -= f * v;
                } else {
                    low.erase(low.find(old));
                }
            }
            auto cur = make_pair(f + 1, v);
            high.insert(cur);
            sumHigh += (f + 1) * v;

            if ((int)high.size() > x) {
                auto it = high.begin();
                sumHigh -= it->first * it->second;
                low.insert(*it);
                high.erase(it);
            }
        };

        auto remove = [&](int v) {
            long long f = freq[v]--;
            auto old = make_pair(f, v);

            if (high.count(old)) {
                high.erase(high.find(old));
                sumHigh -= f * v;
            } else {
                low.erase(low.find(old));
            }

            if (f > 1) {
                low.insert({f - 1, v});
            }

            if ((int)high.size() < x && !low.empty()) {
                auto it = prev(low.end());
                high.insert(*it);
                sumHigh += it->first * it->second;
                low.erase(it);
            }
        };

        for (int i = 0; i < (int)nums.size(); i++) {
            add(nums[i]);
            if (i >= k) remove(nums[i - k]);
            if (i >= k - 1) ans.push_back(sumHigh);
        }

        return ans;
    }
};