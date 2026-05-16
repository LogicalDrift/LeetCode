# Reverse Words in a String

## Problem

Given a string `s`, reverse the order of the words.

Rules:
- Words are separated by spaces
- Remove leading/trailing spaces
- Reduce multiple spaces between words to a single space

Return the reversed sentence.

---

## Examples

### Example 1

```text
Input: s = "the sky is blue"
Output: "blue is sky the"
```

---

### Example 2

```text
Input: s = "  hello world  "
Output: "world hello"
```

---

### Example 3

```text
Input: s = "a good   example"
Output: "example good a"
```

---

## Constraints

- `1 <= s.length <= 10^4`
- `s` contains English letters, digits, and spaces
- At least one word exists

---

## Code

```cpp
class Solution {
public:
    string reverseWords(string s) {
        string ans="", temp="";
        int i=s.size()-1;

        while (i>=0){

            if (s[i]!=' '){
                temp+=s[i];
            }

            else{

                reverse(temp.begin(),temp.end());

                if (temp!=""){

                    if (ans!=""){
                        ans+=" ";
                    }

                    ans+=temp;
                }

                temp="";
            }

            i--;
        }

        reverse(temp.begin(),temp.end());

        if (temp!=""){

            if (ans!=""){
                ans+=" ";
            }

            ans+=temp;
        }

        return ans;
    }
};
```

---

## 🧩 How I Solved It — Step-by-Step

### 1️⃣ Traverse From the End

We start from the last character:

```cpp
int i = s.size() - 1;
```

This naturally helps us build words in reverse order.

---

### 2️⃣ Build Current Word

If current character is not a space:

```cpp
temp += s[i];
```

Since traversal is backward:
- Word gets stored reversed

Example:

```text
"blue"
→ "eulb"
```

---

### 3️⃣ Reverse the Word Back

Before adding to answer:

```cpp
reverse(temp.begin(), temp.end());
```

This restores original word order.

---

### 4️⃣ Ignore Extra Spaces

We only add words when:

```cpp
temp != ""
```

This automatically removes:
- Leading spaces
- Trailing spaces
- Multiple spaces

---

### 5️⃣ Add Spaces Carefully

Before appending a new word:

```cpp
if (ans != ""){
    ans += " ";
}
```

This ensures:
- Only one space between words
- No extra spaces at ends

---

### 6️⃣ Handle Last Word

After loop ends, one word may still remain in `temp`.

So we process it separately.

---

## 🛠️ Possible Improvements

### Use Stack or Stringstream

Alternative approaches:
- Stack of words
- `stringstream`

But your approach avoids extra parsing structures.

---

### Better Variable Names

Instead of:

```cpp
ans, temp
```

Could use:

```cpp
result, word
```

for readability.

---

## 🧠 Time & Space Complexity

### ⏱️ Time Complexity

```text
O(n)
```

Each character is processed a constant number of times.

---

### 🗂️ Space Complexity

```text
O(n)
```

Extra strings used for answer construction.
