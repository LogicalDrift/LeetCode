# Set Mismatch

## Problem

You are given an integer array `nums` representing a set containing numbers from `1` to `n`.

Due to an error:
- One number appears twice
- One number is missing

Return the duplicated number and the missing number.

---

## Examples

### Example 1

```text
Input: nums = [1,2,2,4]
Output: [2,3]
```

---

### Example 2

```text
Input: nums = [1,1]
Output: [1,2]
```

---

## Constraints

- `2 <= nums.length <= 10^4`
- `1 <= nums[i] <= 10^4`

---

## Code

```cpp
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();

        long long s1 = 0, s2 = 0;

        for (int i : nums) {
            s1 += i;
            s2 += 1LL * i * i;
        }

        long long s = 1LL * n * (n + 1) / 2;

        long long diff1 = s - s1;

        long long S = 1LL * n * (n + 1) * (2 * n + 1) / 6;

        long long diff2 = S - s2;

        int miss = (diff2 / diff1 + diff1) / 2;

        int dupl = miss - diff1;

        return {dupl, miss};
    }
};
```

---

## 🧩 How I Solved It — Step-by-Step

### 1️⃣ Define Missing and Duplicate

Suppose:
- Missing number = `x`
- Duplicate number = `y`

Then:

```text
Actual Sum - Current Sum = x - y
```

and

```text
Actual Square Sum - Current Square Sum = x² - y²
```

---

### 2️⃣ Calculate Array Sum

We compute:

```cpp
s1
```

which is the sum of all elements in the array.

Also:

```cpp
s2
```

which stores sum of squares.

---

### 3️⃣ Calculate Expected Sum

For numbers `1 → n`:

```cpp
s = n * (n + 1) / 2
```

Expected square sum:

```cpp
S = n * (n + 1) * (2 * n + 1) / 6
```

---

### 4️⃣ Find Equations

Difference of sums:

```cpp
diff1 = x - y
```

Difference of squares:

```cpp
diff2 = x² - y²
```

Using identity:

```text
x² - y² = (x - y)(x + y)
```

we get:

```text
x + y = diff2 / diff1
```

---

### 5️⃣ Solve for Missing and Duplicate

Now we have:

```text
x - y = diff1
x + y = diff2 / diff1
```

Adding both:

```text
2x = (diff2 / diff1) + diff1
```

So:

```cpp
miss = (diff2 / diff1 + diff1) / 2;
```

Then:

```cpp
dupl = miss - diff1;
```

---

## 🛠️ Possible Improvements

### Use XOR Approach

Another optimized approach uses XOR operations to avoid large-number calculations.

---

### Why Use long long?

Square sums can become large:

```cpp
i * i
```

So `long long` prevents integer overflow.

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
O(1)
```

Only constant extra variables are used.
