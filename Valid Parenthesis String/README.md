# Valid Parenthesis String

## Problem

Given a string `s` containing only:

- `'('`
- `')'`
- `'*'`

Return `true` if the string is valid.

Rules for validity:

- Every `'('` must have a matching `')'`
- Every `')'` must have a matching `'('`
- `'('` must appear before its matching `')'`
- `'*'` can act as:
  - `'('`
  - `')'`
  - empty string `""`

---

## Examples

### Example 1

```text
Input: s = "()"
Output: true
```

---

### Example 2

```text
Input: s = "(*)"
Output: true
```

---

### Example 3

```text
Input: s = "(*))"
Output: true
```

---

## Constraints

- `1 <= s.length <= 100`
- `s[i]` is `'('`, `')'`, or `'*'`

---

## Code

```cpp
class Solution {
public:
    bool checkValidString(string s) {
        int low=0, high=0;

        for (char c : s){

            if (c=='('){
                low++;
                high++;
            }

            else if (c==')'){
                low--;
                high--;
            }

            else if (c=='*'){
                low--;
                high++;
            }

            if (high<0){
                return false;
            }

            if (low<0){
                low=0;
            }
        }

        return low==0;
    }
};
```

---

## 🧩 How I Solved It — Step-by-Step

### 1️⃣ Track Possible Open Parentheses Range

We maintain two variables:

```cpp
low
high
```

Where:
- `low` → minimum possible open brackets
- `high` → maximum possible open brackets

---

### 2️⃣ Handle `'('`

A left parenthesis definitely increases open brackets.

```cpp
low++;
high++;
```

---

### 3️⃣ Handle `')'`

A right parenthesis closes one open bracket.

```cpp
low--;
high--;
```

---

### 4️⃣ Handle `'*'`

`'*'` is flexible.

It can behave as:
- `'('`
- `')'`
- empty string

So:
- Minimum open count decreases
- Maximum open count increases

```cpp
low--;
high++;
```

---

### 5️⃣ Invalid Case

If:

```cpp
high < 0
```

it means too many closing brackets appeared.

So return:

```cpp
false
```

immediately.

---

### 6️⃣ Keep `low` Non-Negative

Minimum open brackets can never actually be negative.

```cpp
if (low < 0){
    low = 0;
}
```

---

### 7️⃣ Final Check

At the end:

```cpp
low == 0
```

means there exists at least one valid interpretation.

---

## 🛠️ Possible Improvements

### Better Variable Names

Instead of:

```cpp
low, high
```

Could use:

```cpp
minOpen, maxOpen
```

for better readability.

---

### Why Greedy Works

This is a greedy range-tracking approach.

Instead of testing every `'*'` possibility:
- We maintain all possible valid ranges simultaneously.

This avoids exponential recursion.

---

## 🧠 Time & Space Complexity

### ⏱️ Time Complexity

```text
O(n)
```

Single traversal of the string.

---

### 🗂️ Space Complexity

```text
O(1)
```

Only two integer variables are used.
