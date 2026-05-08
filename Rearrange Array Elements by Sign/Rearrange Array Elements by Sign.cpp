class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector <int> a(nums.size(),0);
        int even=0,odd=1;
        for (int i : nums){
            if (i>0){
                a[even]=i;
                even+=2;
            }
            else{
                a[odd]=i;
                odd+=2;
            }
        }
        return a;
    }
};
