# How Many Numbers Are Smaller Than the Current Number

## Problem

Given an array `nums`, for each element `nums[i]`, count how many numbers in the array are smaller than it.

Return the result as an array.

---

## Examples

### Example 1

```text
Input: nums = [8,1,2,2,3]
Output: [4,0,1,1,3]
```

---

### Example 2

```text
Input: nums = [6,5,4,8]
Output: [2,1,0,3]
```

---

### Example 3

```text
Input: nums = [7,7,7,7]
Output: [0,0,0,0]
```

---

## Constraints

- `2 <= nums.length <= 500`
- `0 <= nums[i] <= 100`

---

## Code

```cpp
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> freq(101,0);

        for (int i : nums){
            freq[i]++;
        }

        for (int i=1; i<101; i++){
            freq[i]+=freq[i-1];
        }

        vector<int> ans;

        for (int i : nums){

            if (i==0){
                ans.push_back(0);
            }

            else{
                ans.push_back(freq[i-1]);
            }
        }

        return ans;
    }
};
```

---

## 🧩 How I Solved It — Step-by-Step

### 1️⃣ Use Frequency Array

Since:

```text
0 <= nums[i] <= 100
```

we can use counting sort logic.

Create frequency array:

```cpp
vector<int> freq(101,0);
```

where:
- `freq[x]` stores occurrence count of number `x`.

---

### 2️⃣ Count Frequencies

Traverse array:

```cpp
freq[i]++;
```

Now we know how many times each number appears.

---

### 3️⃣ Convert to Prefix Sum

We transform frequency array into cumulative frequency array.

```cpp
freq[i] += freq[i-1];
```

Now:

```text
freq[x]
```

represents:
- count of numbers `<= x`

---

### 4️⃣ Find Smaller Numbers

For number `i`:
- Count of smaller numbers is:

```cpp
freq[i-1]
```

because:
- `freq[i]` includes `i` itself
- We only want strictly smaller numbers

Special case:

```cpp
i == 0
```

No smaller numbers exist.

---

## 🛠️ Possible Improvements

### Preallocate Answer Size

Instead of using:

```cpp
push_back()
```

Could initialize:

```cpp
vector<int> ans(nums.size());
```

Slightly cleaner and avoids resizing.

---

### Alternative Sorting Approach

Another solution:
- Sort copy of array
- Use hashmap for first occurrence index

But counting approach is faster here due to small constraints.

---

## 🧠 Time & Space Complexity

### ⏱️ Time Complexity

```text
O(n + k)
```

Where:
- `n` = size of array
- `k = 101`

Effectively linear.

---

### 🗂️ Space Complexity

```text
O(k)
```

Frequency array of size `101`.
