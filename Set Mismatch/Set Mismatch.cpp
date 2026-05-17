class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();

        long long s1 = 0, s2 = 0;

        for (int i : nums) {
            s1 += i;
            s2 += 1LL * i * i;
        }

        long long s = 1LL * n * (n + 1) / 2;

        long long diff1 = s - s1;

        long long S = 1LL * n * (n + 1) * (2 * n + 1) / 6;

        long long diff2 = S - s2;

        int miss = (diff2 / diff1 + diff1) / 2;

        int dupl = miss - diff1;

        return {dupl, miss};
    }
};
