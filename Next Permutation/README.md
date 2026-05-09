# Next Permutation

## Problem

A permutation of an array of integers is an arrangement of its members into a sequence or linear order.

The next permutation is the next lexicographically greater arrangement of numbers.

If such an arrangement is not possible, rearrange the numbers into the lowest possible order (ascending order).

The replacement must be done in-place using constant extra memory.

---

## Examples

### Example 1

```text
Input: nums = [1,2,3]
Output: [1,3,2]
```

### Example 2

```text
Input: nums = [3,2,1]
Output: [1,2,3]
```

### Example 3

```text
Input: nums = [1,1,5]
Output: [1,5,1]
```

---

## Constraints

- `1 <= nums.length <= 100`
- `0 <= nums[i] <= 100`

---

## Code

```cpp
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i=nums.size()-1, j=nums.size()-1;

        while (i>0 && nums[i-1] >= nums[i]){
            i--;
        }

        if (i==0){
            reverse(nums.begin(), nums.end());
            return;
        }

        while (j>=i && nums[j]<=nums[i-1]){
            j--;
        }

        swap(nums[i-1], nums[j]);

        reverse(nums.begin()+i, nums.end());
    }
};
```

---

## 🧩 How I Solved It — Step-by-Step

### 1️⃣ Find the Breakpoint

Traverse from right to left and find the first index where:

```cpp
nums[i-1] < nums[i]
```

This identifies the point where the permutation can be increased.

Example:

```text
1 2 5 4 3
    ^
```

Here:
- `2 < 5`
- So index `1` is the breakpoint.

---

### 2️⃣ Handle Descending Order

If no breakpoint exists:

```text
3 2 1
```

It means the array is the largest permutation already.

So we reverse the whole array to get the smallest permutation:

```text
1 2 3
```

---

### 3️⃣ Find the Next Greater Element

From the right side, find the first element greater than:

```cpp
nums[i-1]
```

Then swap them.

Example:

```text
1 2 5 4 3
```

Swap `2` with `3`:

```text
1 3 5 4 2
```

---

### 4️⃣ Reverse the Remaining Part

The suffix after index `i-1` is in descending order.

Reverse it to make it the smallest possible arrangement.

Example:

```text
1 3 5 4 2
```

After reversing suffix:

```text
1 3 2 4 5
```

This becomes the next lexicographical permutation.

---

## 🛠️ Possible Improvements

### Use STL Function

C++ already provides:

```cpp
next_permutation(nums.begin(), nums.end());
```

But implementing manually is important for interviews.

---

### Better Variable Names

Instead of:

```cpp
i, j
```

Could use:

```cpp
pivot, successor
```

For better readability.

---

## 🧠 Time & Space Complexity

### ⏱️ Time Complexity

```text
O(n)
```

We traverse the array a constant number of times.

---

### 🗂️ Space Complexity

```text
O(1)
```

In-place modification with constant extra memory.
