# Minimum Distance to the Target Element

## Problem

Given an integer array `nums` (0-indexed) and two integers `target` and
`start`, find an index `i` such that:

-   `nums[i] == target`
-   `abs(i - start)` is minimized

Return `abs(i - start)`.

It is guaranteed that `target` exists in the array.

------------------------------------------------------------------------

## Examples

### Example 1

Input: nums = \[1,2,3,4,5\], target = 5, start = 3\
Output: 1

### Example 2

Input: nums = \[1\], target = 1, start = 0\
Output: 0

### Example 3

Input: nums = \[1,1,1,1,1,1,1,1,1,1\], target = 1, start = 0\
Output: 0

------------------------------------------------------------------------

## Constraints

-   `1 <= nums.length <= 1000`
-   `1 <= nums[i] <= 10^4`
-   `0 <= start < nums.length`
-   `target` exists in `nums`

------------------------------------------------------------------------

## Code

``` cpp
class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int i=start,j=start;
        while (i<nums.size() || j>=0){
            if (j>=0){
                if (nums[j]==target){
                    return start-j;
                }
                j--;
            }
            if (i<nums.size()){
                if (nums[i]==target){
                    return i-start;
                }
                i++;
            }
        }
        return 0;
        
    }
};
```

------------------------------------------------------------------------

## 🧩 How I Solved It --- Step-by-Step

### 1️⃣ Start From the Given Index

We begin from index `start` and expand outward in both directions.

------------------------------------------------------------------------

### 2️⃣ Two-Pointer Expansion

-   `i` moves right
-   `j` moves left

------------------------------------------------------------------------

### 3️⃣ First Match Wins

As soon as we find the target: - Return distance immediately -
Guarantees minimum distance

------------------------------------------------------------------------

## 🛠️ Possible Improvements

### Simpler Approach

``` cpp
int ans = INT_MAX;
for (int i = 0; i < nums.size(); i++) {
    if (nums[i] == target) {
        ans = min(ans, abs(i - start));
    }
}
return ans;
```

------------------------------------------------------------------------

## 🧠 Time & Space Complexity

### ⏱️ Time Complexity

O(n)

### 🗂️ Space Complexity

O(1)
