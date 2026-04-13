class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int i=start,j=start;
        while (i<nums.size() || j>=0){
            if (j>=0){
                if (nums[j]==target){
                    return start-j;
                }
                j--;
            }
            if (i<nums.size()){
                if (nums[i]==target){
                    return i-start;
                }
                i++;
            }
        }
        return 0;
        
    }
};
