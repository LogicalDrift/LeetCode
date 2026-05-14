# Check if Array is Good

## Problem

An array is considered **good** if it is a permutation of:

```text
base[n] = [1, 2, 3, ..., n-1, n, n]
```

Meaning:
- Numbers from `1` to `n-1` appear exactly once
- Number `n` appears exactly twice

Return `true` if the given array is good, otherwise return `false`.

---

## Examples

### Example 1

```text
Input: nums = [2,1,3]
Output: false
```

---

### Example 2

```text
Input: nums = [1,3,3,2]
Output: true
```

---

### Example 3

```text
Input: nums = [1,1]
Output: true
```

---

### Example 4

```text
Input: nums = [3,4,4,1,2,1]
Output: false
```

---

## Constraints

- `1 <= nums.length <= 100`
- `1 <= nums[i] <= 200`

---

## Code

```cpp
class Solution {
public:
    bool isGood(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        int n=nums.size();

        for (int i=0; i<n-1; i++){

            if (nums[i]!=i+1){
                return false;
            }
        }

        return nums[n-1]==n-1;
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

After sorting, a valid good array should look like:

```text
1 2 3 ... n-1 n-1
```

because array size is:
- `n`
- maximum value should be `n-1`

---

### 2️⃣ Verify First n-1 Elements

Loop through indices:

```cpp
0 → n-2
```

Check:

```cpp
nums[i] == i + 1
```

This ensures:
- `1` appears once
- `2` appears once
- ...
- `n-1` appears in correct order

---

### 3️⃣ Check Last Element

The final element must also equal:

```cpp
n - 1
```

because the maximum number appears twice.

```cpp
return nums[n-1] == n-1;
```

---

## 🛠️ Possible Improvements

### Use More Descriptive Variable Names

Instead of:

```cpp
n
```

Could use:

```cpp
size
```

for better readability.

---

### Alternative Frequency Approach

We could use a frequency array or hash map:
- Count occurrences
- Verify counts manually

But sorting makes the implementation cleaner.

---

## 🧠 Time & Space Complexity

### ⏱️ Time Complexity

```text
O(n log n)
```

Due to sorting.

---

### 🗂️ Space Complexity

```text
O(1)
```

Ignoring sorting implementation space.
