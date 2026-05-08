# Rearrange Array Elements by Sign

## Problem

You are given a 0-indexed integer array `nums` of even length consisting of an equal number of positive and negative integers.

Rearrange the array such that:

- Every consecutive pair has opposite signs
- Relative order of positive integers is preserved
- Relative order of negative integers is preserved
- The array starts with a positive integer

Return the modified array.

---

## Examples

### Example 1

```text
Input: nums = [3,1,-2,-5,2,-4]
Output: [3,-2,1,-5,2,-4]
```

### Example 2

```text
Input: nums = [-1,1]
Output: [1,-1]
```

---

## Constraints

- `2 <= nums.length <= 2 * 10^5`
- `nums.length` is even
- `1 <= |nums[i]| <= 10^5`
- Equal number of positive and negative integers

---

## Code

```cpp
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector <int> a(nums.size(),0);
        int even=0,odd=1;

        for (int i : nums){
            if (i>0){
                a[even]=i;
                even+=2;
            }
            else{
                a[odd]=i;
                odd+=2;
            }
        }

        return a;
    }
};
```

---

## 🧩 How I Solved It — Step-by-Step

### 1️⃣ Create a Result Array

We create a new array of the same size as `nums`.

```cpp
vector<int> a(nums.size(),0);
```

---

### 2️⃣ Use Two Indices

We maintain:
- `even` → index for positive numbers
- `odd` → index for negative numbers

```cpp
int even = 0;
int odd = 1;
```

Since the array must begin with a positive number:
- Positive numbers go to even indices
- Negative numbers go to odd indices

---

### 3️⃣ Traverse the Original Array

For each element:
- If positive → place at `even`
- If negative → place at `odd`

After placing:
- Move `even` by `2`
- Move `odd` by `2`

---

### 4️⃣ Preserve Order

Because we process numbers from left to right:
- Positive order remains unchanged
- Negative order remains unchanged

---

## 🛠️ Possible Improvements

### Better Variable Names

Instead of:

```cpp
even, odd
```

We could use:

```cpp
positiveIndex, negativeIndex
```

For better readability.

---

### In-Place Rearrangement

This solution uses extra space.

An in-place solution exists but is more complicated.

---

## 🧠 Time & Space Complexity

### ⏱️ Time Complexity

```text
O(n)
```

Single traversal of the array.

---

### 🗂️ Space Complexity

```text
O(n)
```

Extra array is used for storing the rearranged result.
