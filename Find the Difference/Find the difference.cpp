class Solution {
public:
    char findTheDifference(string s, string t) {
        int ssum=0;
        for (char c : s){
            ssum+=c;
        }
        int tsum=0;
        for (char c : t){
            tsum+=c;
        }
        return (char)(tsum-ssum);
    }
};
