# 796. Rotate String

## Problem Statement

Given two strings `s` and `goal`, return `true` if and only if `s` can become `goal` after some number of **shifts** on `s`.

A shift consists of moving the leftmost character of `s` to the rightmost position.

### Example 1

**Input:**
```text
s = "abcde", goal = "cdeab"
```

**Output:**
```text
true
```

**Explanation:**

After two shifts, `s` becomes `"cdeab"`, which is equal to `goal`.

### Example 2

**Input:**
```text
s = "abcde", goal = "abced"
```

**Output:**
```text
false
```

---

## Approach: KMP (Knuth-Morris-Pratt) Algorithm

### Intuition

Instead of performing rotations one by one, we can use a string property.

If `goal` is a rotation of `s`, then `goal` must be present as a substring in `s + s`.

For example:

```text
s = "abcde"

s + s = "abcdeabcde"

goal = "cdeab"
```

Since `"cdeab"` exists inside `"abcdeabcde"`, it is a valid rotation.

We use the **KMP string matching algorithm** to efficiently search for `goal` inside `s + s`.

### Algorithm

**1. Check string lengths**

- If `s.length() != goal.length()`, return `false`.
- A rotation cannot change the length of a string.

**2. Create the combined string**

```cpp
string text = s + s;
```

This contains every possible rotation of `s` as a substring of length `s.length()`.

**3. Build the LPS array**

LPS stands for **Longest Proper Prefix which is also a Suffix**.

- Create an LPS array of size `goal.length()`.
- For every position, calculate the length of the longest proper prefix that is also a suffix.
- Use this information to avoid unnecessary comparisons when a mismatch occurs.

**4. Perform KMP pattern matching**

- Use `i` to traverse `text`.
- Use `j` to traverse `goal`.
- If characters match, increment both pointers.
- If a mismatch occurs, use the LPS array to move `j` backward without resetting it to zero.
- If `j == m`, the complete `goal` has been found, so return `true`.

**5. Return the result**

If the complete pattern is not found, return `false`.

---

## C++ Solution

```cpp
class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.length() != goal.length()) return false;

        string text = s + s;
        int n = text.length(), m = goal.length();

        vector<int> lps(m, 0);
        int len = 0, i = 1;

        // Build LPS array
        while (i < m) {
            if (goal[i] == goal[len]) {
                len++;
                lps[i] = len;
                i++;
            }
            else {
                if (len != 0) {
                    len = lps[len - 1];
                }
                else {
                    lps[i] = 0;
                    i++;
                }
            }
        }

        // KMP pattern matching
        i = 0;
        int j = 0;

        while (i < n) {
            if (text[i] == goal[j]) {
                i++;
                j++;
            }

            if (j == m) {
                return true;
            }
            else if (i < n && text[i] != goal[j]) {
                if (j != 0)
                    j = lps[j - 1];
                else
                    i++;
            }
        }

        return false;
    }
};
```

---

## Complexity Analysis

Let `n` be the length of `s` and `m` be the length of `goal`.

### Worst-Case Time Complexity: O(n + m)

- Creating `text = s + s` takes O(n).
- Building the LPS array takes O(m).
- KMP pattern matching takes O(n + m).
- Therefore, the overall worst-case time complexity is **O(n + m)**.

Since the strings must have equal lengths, `n = m`.

**Overall: O(n)**

### Worst-Case Auxiliary Space Complexity: O(m)

- The LPS array requires O(m) space.
- The combined string `text` requires O(n) additional space.
- Therefore, total additional space is O(n + m), which becomes O(n) when both strings have equal lengths.

**Overall Auxiliary Space: O(m)** for the KMP algorithm, excluding the combined string.  
**Total Additional Space: O(n + m) = O(n)**, including the combined string.

---

## Key Concepts Learned

- String concatenation
- String pattern matching
- KMP Algorithm
- LPS (Longest Proper Prefix which is also Suffix)
- Efficient handling of pattern mismatches

## Important Observation

The key trick in this problem is:

```cpp
string text = s + s;
```

Every possible rotation of `s` can be found as a substring in `s + s`.

KMP makes searching for that substring efficient, avoiding the need to check every possible rotation separately.
