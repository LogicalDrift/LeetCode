class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> freq(101,0);

        for (int i : nums){
            freq[i]++;
        }

        for (int i=1; i<101; i++){
            freq[i]+=freq[i-1];
        }

        vector<int> ans;
        for (int i : nums){
            if (i==0){
                ans.push_back(0);
            }
            else{
                ans.push_back(freq[i-1]);
            }
        }
        return ans;
    }
};
