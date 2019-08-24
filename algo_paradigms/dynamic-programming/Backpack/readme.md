# BackpackI-IV

## Backpack_I

### Description

Given n items with size Ai, an integer m denotes the size of a backpack. How full you can fill this backpack?

**Note:**

- **You can not divide any item into small pieces.**

### Example

```
Example 1:
Input:  [3,4,8,5], backpack size=10
Output:  9

Example 2:
Input:  [2,3,5,7], backpack size=12
Output:  12
```

### Challenge

O(n x m) time and O(m) memory.

O(n x m) memory is also acceptable if you do not know how to optimize memory.

### Solutions
#### [recursive](./Backpack_I/Solution_recursive.cpp)

```c++
#include <iostream>
#include <vector>

using namespace std;

class Solution {
//    44% test cases passedTotal runtime 3317 ms
public:
    int backPack(int m, vector<int> &A) {
        return helper(m, A, A.size());
    }

private:
    int max(int a, int b) {
        return a > b ? a : b;
    }

    int helper(int m, vector<int> &A, int n) {
        if (m <= 0 || n == 0)
            return 0;
        if (m < A[n - 1])
            return helper(m, A, n - 1);
        return max(A[n - 1] + helper(m - A[n - 1], A, n - 1), helper(m, A, n - 1));
    }
};

int main() {
    auto *so = new Solution();
    vector<int> nums{2, 3, 5, 7};
    int size = 12;
    int res = so->backPack(size, nums);
    cout << res << endl;
    delete so;
    return 0;
}
```



#### [dp](./Backpack_I/Solution_dp.cpp)

```c++
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int backPack(int m, vector<int> &A) {
        // write your code here
        int len = A.size();
        int dp[len][m + 1];
        for (int i = 0; i <= m; i++) {
            if (i >= A[0]) {
                dp[0][i] = A[0];
            } else
                dp[0][i] = 0;
        }

        for (int i = 1; i < len; i++) {
            for (int j = 0; j <= m; j++) {
                if (j >= A[i]) {
                    dp[i][j] = max(dp[i - 1][j - A[i]] + A[i], dp[i - 1][j]);
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[len - 1][m];
    }

    int max(int a, int b) {
        return a > b ? a : b;
    }
};

int main() {
    auto *so = new Solution();
    vector<int> nums{2, 3, 5, 7};
    int size = 12;
    int res = so->backPack(size, nums);
    cout << res << endl;
    delete so;
    return 0;
}
```



#### [dp-space-optimized](./Backpack_I/Solution_dp_space_optimized.cpp)

```c++
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int backPack(int m, vector<int> &A) {
        // write your code here
        int len = A.size();
        int dp[2][m + 1];
        bool bi;
        for (int i = 0; i <= m; i++) {
            if (i >= A[0]) {
                dp[0][i] = A[0];
            } else
                dp[0][i] = 0;
        }

        for (int i = 1; i < len; i++) {
            bi = i & 1;
            for (int j = 0; j <= m; j++) {
                if (j >= A[i]) {
                    dp[bi][j] = max(dp[1 - bi][j - A[i]] + A[i], dp[1 - bi][j]);
                } else {
                    dp[bi][j] = dp[1 - bi][j];
                }
            }
        }
        return dp[bi][m];
    }

private:
    int max(int a, int b) {
        return a > b ? a : b;
    }

};

int main() {
    auto *so = new Solution();
    vector<int> nums{2, 3, 5, 7};
    int size = 12;
    int res = so->backPack(size, nums);
    cout << res << endl;
    delete so;
    return 0;
}

```



## Backpack_II

### Description

There are n items and a backpack with size m. Given array A representing the size of each item and array V representing the value of each item.

What's the maximum value can you put into the backpack?

**Note:**

- **A[i], V[i], n, m are all integers.**
- **You can not split an item.**
- **The sum size of the items you want to put into backpack can not exceed m.**
- **Each item can only be picked up once**

### Example

```
Example 1:
Input: m = 10, A = [2, 3, 5, 7], V = [1, 5, 2, 4]
Output: 9
Explanation: Put A[1] and A[3] into backpack, getting the maximum value V[1] + V[3] = 9

Example 2:
Input: m = 10, A = [2, 3, 8], V = [2, 5, 8]
Output: 10
Explanation: Put A[0] and A[2] into backpack, getting the maximum value V[0] + V[2] = 10
```

### Challenge

O(nm) memory is acceptable, can you do it in O(m) memory?

### Solutions

#### [recursive](./Backpack_II/Solution_recursive.cpp)

```c++
#include <iostream>
#include <vector>

using namespace std;

class SolutionRecursion {
//    36% test cases passedTotal runtime 1104 ms
public:
    int backPackII(int m, vector<int> &A, vector<int> &V) {
        // write your code here
        int len = A.size();
        return helper(m, A, V, len);
    }

private:
    int helper(int m, vector<int> &A, vector<int> &V, int len) {
        if (m == 0 || len == 0)
            return 0;
        if (m < A[len - 1])
            return helper(m, A, V, len - 1);
        else
            return max(V[len - 1] + helper(m - A[len - 1], A, V, len - 1), helper(m, A, V, len - 1));
    }

    int max(int a, int b) {
        return a > b ? a : b;
    }
};

int main() {
    auto *so = new SolutionRecursion();
    vector<int> A{2, 3, 5, 7};
    vector<int> V{1, 5, 2, 4};
    int m = 10;
    int res = so->backPackII(m, A, V);
    cout << res << endl;
    delete so;
    return 0;
}
```



#### [dp](./Backpack_II/Solution_dp.cpp)

```c++
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int backPackII(int m, vector<int> &A, vector<int> &V) {
        // write your code here
        int len = A.size();
        int dp[len + 1][m + 1];
        for (int i = 0; i < len + 1; i++) {
            for (int j = 0; j < m + 1; j++) {
                if (i == 0 || j == 0)
                    dp[i][j] = 0;
                else if (j < A[i - 1])
                    dp[i][j] = dp[i - 1][j];
                else
                    dp[i][j] = max(V[i - 1] + dp[i - 1][j - A[i - 1]], dp[i - 1][j]);
            }
        }
        return dp[len][m];
    }

private:
    int max(int a, int b) {
        return a > b ? a : b;
    }
};

int main() {
    auto *so = new Solution();
    vector<int> A{2, 3, 5, 7};
    vector<int> V{1, 5, 2, 4};
    int m = 10;
    int res = so->backPackII(m, A, V);
    cout << res << endl;
    delete so;
    return 0;
}
```



#### [dp-space-optimized](./Backpack_II/Solution_dp_space_optimized.cpp)

```c++
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int backPackII(int m, vector<int> &A, vector<int> &V) {
        // write your code here
        int len = A.size();
        int dp[2][m + 1];
        bool bi;
        for (int i = 0; i < len + 1; i++) {
            bi = i & 1;
            for (int j = 0; j < m + 1; j++) {
                if (i == 0 || j == 0)
                    dp[bi][j] = 0;
                else if (j < A[i - 1])
                    dp[bi][j] = dp[1 - bi][j];
                else
                    dp[bi][j] = max(V[i - 1] + dp[1 - bi][j - A[i - 1]], dp[1 - bi][j]);
            }
        }
        return dp[bi][m];
    }

private:
    int max(int a, int b) {
        return a > b ? a : b;
    }
};

int main() {
    auto *so = new Solution();
    vector<int> A{2, 3, 5, 7};
    vector<int> V{1, 5, 2, 4};
    int m = 10;
    int res = so->backPackII(m, A, V);
    cout << res << endl;
    delete so;
    return 0;
}
```




## Backpack_III

### Description

Given n kinds of items, and each kind of item has an infinite number available. The i-th item has size A[i] and value V[i].

Also given a backpack with size m. What is the maximum value you can put into the backpack?

**Note:**

- **You cannot divide item into small pieces.**
- **Total size of items you put into backpack can not exceed m.**

### Example

```
Example 1:
Input: A = [2, 3, 5, 7], V = [1, 5, 2, 4], m = 10
Output: 15
Explanation: Put three item 1 (A[1] = 3, V[1] = 5) into backpack.

Example 2:
Input: A = [1, 2, 3], V = [1, 2, 3], m = 5
Output: 5
Explanation: Strategy is not unique. For example, put five item 0 (A[0] = 1, V[0] = 1) into backpack.
```

### Solutions

#### [recursive](./Backpack_III/Solution_recursive.cpp)

```c++
#include <iostream>
#include <vector>

using namespace std;

class Solution {
//    Time Limit Exceeded
//    46% test cases passed
public:
    int backPackIII(vector<int> &A, vector<int> &V, int m) {
        // write your code here
        int len = A.size();
        return helper(m, A, V, len);
    }

private:
    int helper(int m, vector<int> &A, vector<int> &V, int len) {
        if (m <= 0 || len == 0)
            return 0;
        if (m >= A[len - 1])
            return max(V[len - 1] + helper(m - A[len - 1], A, V, len), helper(m, A, V, len - 1));
        else
            return helper(m, A, V, len - 1);
    }

    int max(int a, int b) {
        return a > b ? a : b;
    }
};

int main() {
    auto *so = new Solution();
    vector<int> A{2, 3, 5, 7};
    vector<int> V{1, 5, 2, 4};
    int m = 10;
    int res = so->backPackIII(A, V, m);
    cout << res << endl;
    delete so;
    return 0;
}
```



#### [dp](./Backpack_III/Solution_dp.cpp)

```c++
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int backPackIII(vector<int> &A, vector<int> &V, int m) {
        // write your code here
        int len = A.size();
        int dp[len + 1][m + 1];
        for (int i = 0; i < len + 1; i++) {
            for (int j = 0; j < m + 1; j++) {
                if (i == 0 || j == 0)
                    dp[i][j] = 0;
                else if (j < A[i - 1])
                    dp[i][j] = dp[i - 1][j];
                else
                    dp[i][j] = max(V[i - 1] + dp[i][j - A[i - 1]], dp[i - 1][j]);
            }
        }
        return dp[len][m];
    }

private:
    int max(int a, int b) {
        return a > b ? a : b;
    }
};

int main() {
    auto *so = new Solution();
    vector<int> A{2, 3, 5, 7};
    vector<int> V{1, 5, 2, 4};
    int m = 10;
    int res = so->backPackIII(A, V, m);
    cout << res << endl;
    delete so;
    return 0;
}
```



#### [dp-space-optimized](./Backpack_III/Solution_dp_space_optimized.cpp)

```c++
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int backPackIII(vector<int> &A, vector<int> &V, int m) {
        // write your code here
        int len = A.size();
        int dp[2][m + 1];
        bool bi;
        for (int i = 0; i < len + 1; i++) {
            bi = i & 1;
            for (int j = 0; j < m + 1; j++) {
                if (i == 0 || j == 0)
                    dp[bi][j] = 0;
                else if (j < A[i - 1])
                    dp[bi][j] = dp[1 - bi][j];
                else
                    dp[bi][j] = max(V[i - 1] + dp[bi][j - A[i - 1]], dp[1 - bi][j]);
            }
        }
        return dp[bi][m];
    }

private:
    int max(int a, int b) {
        return a > b ? a : b;
    }
};

int main() {
    auto *so = new Solution();
    vector<int> A{2, 3, 5, 7};
    vector<int> V{1, 5, 2, 4};
    int m = 10;
    int res = so->backPackIII(A, V, m);
    cout << res << endl;
    delete so;
    return 0;
}
```




## Backpack_IV

### Description

Given an integer array nums[] which contains n unique positive numbers, num[i] indicate the size of ith item. An integer target denotes the size of backpack. Find the number of ways to fill the backpack.

**Note:**

- **Each item may be chosen unlimited number of times**

### Example

```
Example1
Input: nums = [2,3,6,7] and target = 7
Output: 2
Explanation:
Solution sets are:
[7]
[2, 2, 3]

Example2
Input: nums = [2,3,4,5] and target = 7
Output: 3
Explanation:
Solution sets are:
[2, 5]
[3, 4]
[2, 2, 3]
```

### Solutions

#### [dp](./Backpack_IV/Solution_dp.cpp)

```c++
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int backPackIV(vector<int> &nums, int target) {
        // Write your code here
        vector<int> dp(target + 1);
        dp[0] = 1;
        for (auto a : nums) {
            for (int i = a; i <= target; ++i) {
                dp[i] += dp[i - a];
            }
        }
        return dp.back();
    }
};

int main() {
    auto *so = new Solution();
    vector<int> nums{2, 3, 6, 7};
    int target = 7;
    int res = so->backPackIV(nums, target);
    cout << res << endl;
    delete so;
    return 0;
}
```




## Backpack_V

### Description

Given n items with size nums[i] which an integer array and all positive numbers. An integer target denotes the size of a backpack. Find the number of possible fill the backpack.

**Note:**

- **Each item may only be used once**

### Example

```
Given candidate items [1,2,3,3,7] and target 7,

A solution set is:
[7]
[1, 3, 3]
return 2
```
### Solutions


#### [dp](./Backpack_V/Solution_dp.cpp)

```c++
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int backPackV(vector<int> &nums, int target) {
        // Write your code here
        vector<int> dp(target + 1);
        dp[0] = 1;
        for (auto a : nums) {
            for (int i = target; i >= a; --i) {
                dp[i] += dp[i - a];
            }
        }
        return dp.back();
    }
};

int main() {
    auto *so = new Solution();
    vector<int> nums{1, 2, 3, 3, 7};
    int target = 7;
    int res = so->backPackV(nums, target);
    cout << res << endl;
    delete so;
    return 0;
}
```




## Backpack_VI

### Description

Given an integer array nums with all positive numbers and no duplicates, find the number of possible combinations that add up to a positive integer target.

**Note:**

- **A number in the array can be used multiple times in the combination.**
- **Different orders are counted as different combinations.**


### Example

```
Example1

Input: nums = [1, 2, 4], and target = 4
Output: 6
Explanation:
The possible combination ways are:
[1, 1, 1, 1]
[1, 1, 2]
[1, 2, 1]
[2, 1, 1]
[2, 2]
[4]
Example2

Input: nums = [1, 2], and target = 4
Output: 5
Explanation:
The possible combination ways are:
[1, 1, 1, 1]
[1, 1, 2]
[1, 2, 1]
[2, 1, 1]
[2, 2]
```

### Solutions

#### [dp](./Backpack_VI/Solution_dp.cpp)

```c++
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int combinationSum4(vector<int> &nums, int target) {
        int n = nums.size();
        unsigned long f[target + 1];
        memset(f, 0, sizeof(f));
        f[0] = 1;
        for (int i = 1; i <= target; i++) {
            for (int j = 0; j < n; j++)
                if (i - nums[j] >= 0) {
                    f[i] += f[i - nums[j]];
                }
        }
        return f[target];
    }
};

int main() {
    auto *so = new Solution();
    vector<int> nums{1, 2, 4};
    int target = 4;
    int res = so->combinationSum4(nums, target);
    cout << res << endl;
    delete so;
    return 0;
}
```

