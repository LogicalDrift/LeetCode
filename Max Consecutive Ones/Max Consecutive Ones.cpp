class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int temp=0, max=0;
        for (int i : nums){
            if (i==1){
                temp++;
            }
            else{
                if (temp>max){
                    max=temp;
                }
                temp=0;
            }
        }
        if (temp>max){
            return temp;
        }
        return max;
    }
};
