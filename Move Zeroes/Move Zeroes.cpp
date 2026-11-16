class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i=0, j=0;
        while (i<nums.size()){
            if (nums[i]==0){
                i++;
            }
            else {
                int temp=nums[i];
                nums[i]=nums[j];
                nums[j]=temp;
                j++;
                i++;
            }
        }
    }
};
