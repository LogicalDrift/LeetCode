class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i=0,j=0;
        string s="";
        for ( i=0,j=0; i<word1.length() and j<word2.length(); i++,j++){
            s=s+word1[i]+word2[j];
        }
        while (i<word1.length()){
            s=s+word1[i];
            i++;
        }
        while (j<word2.length()){
            s=s+word2[j];
            j++;
        }
        return s;
    }
};
