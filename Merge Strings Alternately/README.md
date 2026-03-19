# Merge Strings Alternately

## Problem

You are given two strings `word1` and `word2`. Merge them by adding
letters in alternating order, starting with `word1`.

If one string is longer, append the remaining characters at the end.

Return the merged string.

------------------------------------------------------------------------

## Examples

### Example 1

Input: word1 = "abc", word2 = "pqr"\
Output: "apbqcr"

### Example 2

Input: word1 = "ab", word2 = "pqrs"\
Output: "apbqrs"

### Example 3

Input: word1 = "abcd", word2 = "pq"\
Output: "apbqcd"

------------------------------------------------------------------------

## Constraints

-   `1 <= word1.length, word2.length <= 100`
-   Strings contain only lowercase English letters

------------------------------------------------------------------------

## Code

``` cpp
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
```

------------------------------------------------------------------------

## 🧩 How I Solved It --- Step-by-Step

### 1️⃣ Use Two Pointers

We use two indices: - `i` for `word1` - `j` for `word2`

------------------------------------------------------------------------

### 2️⃣ Alternate Characters

We loop while both strings still have characters: - Add `word1[i]` - Add
`word2[j]`

------------------------------------------------------------------------

### 3️⃣ Handle Remaining Characters

If one string is longer: - Append remaining characters of `word1` -
Append remaining characters of `word2`

------------------------------------------------------------------------

## 🛠️ Possible Improvements

### Avoid String Concatenation Overhead

Using `s = s + ...` creates new strings repeatedly.

Better approach:

``` cpp
string s;
s.reserve(word1.size() + word2.size());
```

------------------------------------------------------------------------

## 🧠 Time & Space Complexity

### ⏱️ Time Complexity

O(n + m)

### 🗂️ Space Complexity

O(n + m)
