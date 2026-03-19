# Find the Difference

## Problem

You are given two strings `s` and `t`.

-   String `t` is created by shuffling string `s`
-   Then one extra character is added at a random position

Return the character that was added.

------------------------------------------------------------------------

## Examples

### Example 1

Input: s = "abcd", t = "abcde"\
Output: "e"

### Example 2

Input: s = "", t ="y"\
Output: "y"

------------------------------------------------------------------------

## Constraints

-   `0 <= s.length <= 1000`
-   `t.length == s.length + 1`
-   Strings contain only lowercase English letters

------------------------------------------------------------------------

## Code

``` cpp
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
```

------------------------------------------------------------------------

## 🧩 How I Solved It --- Step-by-Step

### 1️⃣ Key Idea

Since `t` has exactly **one extra character**, we can compare the total
sum of ASCII values.

------------------------------------------------------------------------

### 2️⃣ Compute Sum of s

We iterate through string `s` and add all character values.

------------------------------------------------------------------------

### 3️⃣ Compute Sum of t

We do the same for string `t`.

------------------------------------------------------------------------

### 4️⃣ Find the Difference

The extra character is:

    tsum - ssum

Convert it back to a character and return.

------------------------------------------------------------------------

## 🛠️ Possible Improvements

### Use XOR (Better Approach)

Instead of summation, XOR is safer and cleaner:

``` cpp
char result = 0;
for (char c : s) result ^= c;
for (char c : t) result ^= c;
return result;
```

Why? - XOR cancels identical characters - Leaves only the extra
character - Avoids potential overflow

------------------------------------------------------------------------

## 🧠 Time & Space Complexity

### ⏱️ Time Complexity

O(n)

We traverse both strings once.

------------------------------------------------------------------------

### 🗂️ Space Complexity

O(1)

No extra space used.
