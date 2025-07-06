#include <vector>
#include <unordered_map>
using namespace std;

class FindSumPairs {
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2)
        : nums1(nums1), nums2(nums2) {
        buildFrequencyMap();
    }

    void add(int index, int val) {
        int oldVal = nums2[index];
        freqMap[oldVal]--;

        nums2[index] += val;

        freqMap[nums2[index]]++;
    }

    int count(int tot) {
        int result = 0;
        for (int x : nums1) {
            int complement = tot - x;
            if (freqMap.count(complement)) {
                result += freqMap[complement];
            }
        }
        return result;
    }

private:
    vector<int> nums1;
    vector<int> nums2;
    unordered_map<int, int> freqMap;

    void buildFrequencyMap() {
        for (int num : nums2) {
            freqMap[num]++;
        }
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */