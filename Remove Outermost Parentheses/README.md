# Remove Outermost Parentheses

## Problem

A valid parentheses string is considered primitive if it cannot be split into two non-empty valid parentheses strings.

Given a valid parentheses string `s`, remove the outermost parentheses of every primitive substring and return the result.

---

## Examples

### Example 1

```text
Input: s = "(()())(())"
Output: "()()()"
```

Explanation:

```text
"(()())" + "(())"
→ "()()" + "()"
→ "()()()"
```

---

### Example 2

```text
Input: s = "(()())(())(()(()))"
Output: "()()()()(())"
```

---

### Example 3

```text
Input: s = "()()"
Output: ""
```

---

## Constraints

- `1 <= s.length <= 10^5`
- `s[i]` is either `'('` or `')'`
- `s` is a valid parentheses string

---

## Code

```cpp
class Solution {
public:
    string removeOuterParentheses(string s) {
        string a;
        int i=0;

        for (char c : s){

            if (c=='('){

                if (i!=0){
                    a.push_back(c);
                }

                i++;
            }

            else{

                i--;

                if (i!=0){
                    a.push_back(c);
                }
            }
        }

        return a;
    }
};
```

---

## 🧩 How I Solved It — Step-by-Step

### 1️⃣ Track Parentheses Depth

We use a counter:

```cpp
i
```

which represents the current nesting depth.

- `'('` increases depth
- `')'` decreases depth

---

### 2️⃣ Ignore Outermost Opening Bracket

When we encounter `'('`:

```cpp
if (i != 0)
```

Only then do we add it to the result.

Why?
Because when `i == 0`, it means this `'('` is the outermost opening bracket of a primitive substring.

---

### 3️⃣ Ignore Outermost Closing Bracket

For `')'`:

First decrease depth:

```cpp
i--;
```

Then:

```cpp
if (i != 0)
```

add it to the result.

Why?
Because when depth becomes `0`, this `')'` is the outermost closing bracket.

---

### 4️⃣ Build Final String

All inner parentheses are preserved while outermost ones are skipped.

---

## 🛠️ Possible Improvements

### Better Variable Name

Instead of:

```cpp
i
```

Could use:

```cpp
depth
```

for better readability.

---

### Use String Reserve

Since result size is known approximately:

```cpp
a.reserve(s.size());
```

can slightly improve performance.

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
O(n)
```

Extra string used for result.
