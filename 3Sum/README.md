# 3Sum

## Problem

Given an integer array `nums`, return all unique triplets:

```text
[nums[i], nums[j], nums[k]]
```

such that:

- `i != j`
- `i != k`
- `j != k`
- `nums[i] + nums[j] + nums[k] == 0`

The solution set must not contain duplicate triplets.

---

## Examples

### Example 1

```text
Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
```

---

### Example 2

```text
Input: nums = [0,1,1]
Output: []
```

---

### Example 3

```text
Input: nums = [0,0,0]
Output: [[0,0,0]]
```

---

## Constraints

- `3 <= nums.length <= 3000`
- `-10^5 <= nums[i] <= 10^5`

---

## Code

```cpp
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        vector<vector<int>> a;

        for (int i=0; i<nums.size() && nums[i]<=0; i++){

            if (i>0 && nums[i]==nums[i-1]){
                continue;
            }

            int j=i+1,k=nums.size()-1;

            while (j<k){

                if (nums[i]+nums[j]+nums[k]==0){

                    a.push_back({nums[i],nums[j],nums[k]});

                    j++;
                    k--;

                    while (j < k && nums[j] == nums[j - 1]) {
                        j++;
                    }

                    while (j < k && nums[k] == nums[k + 1]) {
                        k--;
                    }
                }

                else if (nums[i]+nums[j]+nums[k]<0){
                    j++;
                }

                else{
                    k--;
                }
            }
        }

        return a;
    }
};
```

---

## 🧩 How I Solved It — Step-by-Step

### 1️⃣ Sort the Array

First, sort the array.

```cpp
sort(nums.begin(), nums.end());
```

Sorting helps:
- Apply two-pointer technique
- Skip duplicates efficiently

---

### 2️⃣ Fix One Number

We use index `i` as the fixed element.

```cpp
for (int i=0; i<nums.size() && nums[i]<=0; i++)
```

Important optimization:

```cpp
nums[i] <= 0
```

Why?
Because once `nums[i]` becomes positive:
- All numbers after it are also positive
- Sum can never become `0`

So we stop early.

---

### 3️⃣ Skip Duplicate Fixed Elements

To avoid duplicate triplets:

```cpp
if (i>0 && nums[i]==nums[i-1]){
    continue;
}
```

---

### 4️⃣ Use Two Pointers

Initialize:

```cpp
j = i + 1
k = nums.size() - 1
```

Then:
- If sum < 0 → move `j`
- If sum > 0 → move `k`
- If sum == 0 → store triplet

---

### 5️⃣ Skip Duplicate Pairs

After finding a valid triplet:

```cpp
while (j < k && nums[j] == nums[j - 1])
```

and

```cpp
while (j < k && nums[k] == nums[k + 1])
```

This prevents duplicate answers.

---

## 🛠️ Possible Improvements

### Store Sum in a Variable

Instead of repeatedly computing:

```cpp
nums[i]+nums[j]+nums[k]
```

Use:

```cpp
int sum = nums[i] + nums[j] + nums[k];
```

Improves readability slightly.

---

### Minor Optimization

Loop condition:

```cpp
i < nums.size()
```

can become:

```cpp
i < nums.size() - 2
```

since at least three elements are needed.

---

## 🧠 Time & Space Complexity

### ⏱️ Time Complexity

```text
O(n²)
```

- Sorting → `O(n log n)`
- Two-pointer traversal for each element → `O(n²)`

Overall:

```text
O(n²)
```

---

### 🗂️ Space Complexity

```text
O(1)
```

Ignoring output storage.
