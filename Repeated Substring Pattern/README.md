# Repeated Substring Pattern

## Problem

Given a string `s`, check if it can be constructed by taking a substring
of it and repeating it multiple times.

Return `true` if possible, otherwise `false`.

------------------------------------------------------------------------

## Examples

### Example 1

Input: s = "abab"\
Output: true

### Example 2

Input: s = "aba"\
Output: false

### Example 3

Input: s = "abcabcabcabc"\
Output: true

------------------------------------------------------------------------

## Constraints

-   `1 <= s.length <= 10^4`
-   String contains only lowercase English letters

------------------------------------------------------------------------

## Code

``` python
class Solution:
    def repeatedSubstringPattern(self, s: str) -> bool:
        return s in (s+s)[1:-1]
```

------------------------------------------------------------------------

## 🧩 How I Solved It --- Step-by-Step

### 1️⃣ Core Trick

We take the string and double it:

s + s

Then remove the first and last characters:

(s + s)\[1:-1\]

------------------------------------------------------------------------

### 2️⃣ Why This Works

If `s` is made by repeating a substring:

-   Then `s` will appear inside this modified string
-   Because shifting removes the original alignment but keeps repeated
    patterns

------------------------------------------------------------------------

### 3️⃣ Example

For s = "abab":

s + s = "abababab"\
(s+s)\[1:-1\] = "bababa"

Now "abab" exists inside "bababa" → return true

------------------------------------------------------------------------

## 🛠️ Possible Improvements

### Alternative Approach

Check all possible substring lengths that divide the string length and
verify repetition.

------------------------------------------------------------------------

## 🧠 Time & Space Complexity

### ⏱️ Time Complexity

O(n)

### 🗂️ Space Complexity

O(n)
