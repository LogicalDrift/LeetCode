class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.length()!=goal.length()) return false;
        string text=s+s;
        int n=text.length(), m=goal.length();
        vector<int> lps(m,0);
        int len=0, i=1;
        while (i<m){
            if (goal[i]==goal[len]){
                len++;
                lps[i]=len;
                i++;
            }
            else {
                if (len!=0){
                    len=lps[len-1];
                }
                else {
                    lps[i]=0;
                    i++;
                }
            }
        }
        
        i=0;
        int j=0;
        while (i<n){
            if (text[i]==goal[j]){
                i++;
                j++;
            }
            if (j==m){
                return true;
            }
            else if (i<n && text[i]!=goal[j]){
                if (j!=0)
                    j=lps[j-1];
                else
                    i++;
            }
        }
        return false;
    }
};
