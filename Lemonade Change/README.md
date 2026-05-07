# Lemonade Change

## Problem

At a lemonade stand:

-   Each lemonade costs `$5`
-   Customers pay using `$5`, `$10`, or `$20`
-   You must provide correct change immediately
-   Initially, you have no change

Return `true` if every customer can receive correct change, otherwise
return `false`.

------------------------------------------------------------------------

## Examples

### Example 1

Input: bills = \[5,5,5,10,20\]\
Output: true

### Example 2

Input: bills = \[5,5,10,10,20\]\
Output: false

------------------------------------------------------------------------

## Constraints

-   `1 <= bills.length <= 10^5`
-   `bills[i]` is either `5`, `10`, or `20`

------------------------------------------------------------------------

## Code

``` cpp
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five=0, ten=0;
        for (int i : bills){
            if (i==5) five++;
            else if (i==10) ten++,five--;
            else if (ten>0) ten--, five--;
            else five-=3;
            if (five<0) return false;
        }
        return true;
    }
};
```

------------------------------------------------------------------------

## 🧩 How I Solved It --- Step-by-Step

### 1️⃣ Track Bills

We only need: - Count of `$5` - Count of `$10`

------------------------------------------------------------------------

### 2️⃣ Handle `$5` Payment

No change required.

``` cpp
five++;
```

------------------------------------------------------------------------

### 3️⃣ Handle `$10` Payment

Need to give back one `$5`.

``` cpp
ten++;
five--;
```

------------------------------------------------------------------------

### 4️⃣ Handle `$20` Payment

Need to return `$15`.

Best greedy choice: - Use one `$10` and one `$5` if possible - Otherwise
use three `$5` bills

This preserves more `$5` bills for future customers.

------------------------------------------------------------------------

### 5️⃣ Invalid Case

If:

``` cpp
five < 0
```

We failed to provide change.

Return `false` immediately.

------------------------------------------------------------------------

## 🛠️ Possible Improvements

### Better Formatting

Adding braces `{}` improves readability and prevents accidental bugs.

------------------------------------------------------------------------

### Greedy Insight

This is a classic greedy problem: - Always preserve smaller bills when
possible - Using `$10 + $5` for `$20` is optimal

------------------------------------------------------------------------

## 🧠 Time & Space Complexity

### ⏱️ Time Complexity

O(n)

Single traversal of the array.

------------------------------------------------------------------------

### 🗂️ Space Complexity

O(1)

Only two integer variables are used.
