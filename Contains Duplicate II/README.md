# Contains Duplicate II

## Problem

Given an integer array `nums` and an integer `k`, return `true` if there
are two distinct indices `i` and `j` such that:

-   `nums[i] == nums[j]`
-   `abs(i - j) <= k`

If such a pair exists, return `true`. Otherwise, return `false`.

------------------------------------------------------------------------

## Examples

### Example 1

Input: nums = \[1,2,3,1\], k = 3\
Output: true

### Example 2

Input: nums = \[1,0,1,1\], k = 1\
Output: true

### Example 3

Input: nums = \[1,2,3,1,2,3\], k = 2\
Output: false

------------------------------------------------------------------------

## Constraints

-   `1 <= nums.length <= 10^5`
-   `-10^9 <= nums[i] <= 10^9`
-   `0 <= k <= 10^5`

------------------------------------------------------------------------

## Code

``` cpp
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        for (int i=0; i<nums.size(); i++){
            for (int j=i+1; j<i+k+1 && j<nums.size(); j++){
                if (nums[i]==nums[j]){
                    return true;
                }
            }
        }
        return false;
    }
};
```

------------------------------------------------------------------------

## 🧩 How I Solved It --- Step-by-Step

### 1️⃣ Check Every Element

We iterate through the array using index `i`.

For each element `nums[i]`, we try to find the same value within the
next `k` indices.

------------------------------------------------------------------------

### 2️⃣ Compare With Next k Elements

For every index `i`, we run another loop from:

j = i + 1

to

j \< i + k + 1

This ensures that the distance between the indices does not exceed `k`.

------------------------------------------------------------------------

### 3️⃣ Check for Duplicate

If:

nums\[i\] == nums\[j\]

then we found two indices whose difference is within `k`, so we return
`true`.

------------------------------------------------------------------------

### 4️⃣ Continue Until End

If no such pair is found after checking the entire array, return
`false`.

------------------------------------------------------------------------

## 🛠️ Possible Improvements

### Use a Hash Set (Sliding Window)

The current approach is brute force.

Worst case complexity:

O(n × k)

A better approach uses a sliding window with a hash set to achieve:

O(n)

------------------------------------------------------------------------

## 🧠 Time & Space Complexity

### ⏱️ Time Complexity

O(n × k)

For every element, we check up to `k` elements ahead.

### 🗂️ Space Complexity

O(1)

No extra data structures are used.
