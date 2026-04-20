#include <bits/stdc++.h>

using namespace std;

// Question 1
// In an array only one element occurs only once and rest elements occur twice. find the element that occurs once
// [2,1,2,5,6,5,7,7,6] // ans: 1
// link: https://practice.geeksforgeeks.org/problems/element-appearing-once2552/1#
int solution1(int arr[], int n)
{
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        ans ^= arr[i];
    }

    return ans;
}

// Property 1
// Swapping values of 2 numbers using XOR
void swapXOR(int &a, int &b)
{
    cout << "a = " << a << ", b = " << b << endl;
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    cout << "a = " << a << ", b = " << b << endl;
}

// Question 2
// Print XOR of numbers 1 to n
int solution2(int n)
{
    int ans = -1;
    switch (n % 4)
    {
    case 0:
        ans = n;
        break;
    case 1:
        ans = 1;
        break;
    case 2:
        ans = n + 1;
        break;
    case 3:
        ans = 0;
        break;
    }
    return ans;
}

// Question 3
// Print XOR of numbers l to r
int solution3(int l, int r)
{
    return solution2(r) ^ solution2(l - 1);
}

// Question 4
// check wheather a number is even or odd
void solution4(int n)
{
    // bitwise operators are very fast then arithmetic operators
    if ((n & 1) == 0)
    {
        cout << "EVEN" << endl;
    }
    else
    {
        cout << "ODD" << endl;
    }
}

// Question 5
// given (n,i) find if ith(0-indexed) bit from right is set or not(i.e one or not)
// i.e n = 13 ( 1 1 0 1 ), i = 2
//              3 2 1 0 => 2nd bit is 1 => return true
bool solution5(int n, int i)
{
    int temp = 1;
    // bool flag = ((n >> i) & 1);
    bool flag = ((temp << i) & n);
    return flag;
}

// Question 6
// set 'i'th bit of 'n' to 1
int solution6(int n, int i)
{
    int temp = n;
    temp |= (1 << i);
    return temp;
}

// Question 7
// clear 'i'th bit of n to 0
int solution7(int n, int i)
{
    int temp = n;
    temp &= ~(1 << i);
    return temp;
}

// Question 8
// remove last set bit of a number
int solution8(int n)
{
    return (n & (n - 1));
}

// Question 9
// check if a number is a power of 2
bool solution9(int n)
{
    return ((n & (n - 1)) == 0);
}

// Question 10
// count number of set bits in 'n'
int solution10(int n)
{
    // Approach 1[O(log(no.of_BITS)][Left-Shift]
    // int temp = 1, ans = 0;
    // while (temp <= n)
    // {
    //     if (n & temp)
    //     {
    //         ++ans;
    //     }
    //     temp <<= 1;
    // }
    // return ans;

    // Approach 2[O(log(no.of_BITS)][Right-Shift]
    // int temp = n, ans = 0;
    // while (temp > 0)
    // {
    //     if ((temp & 1) == 1)
    //     {
    //         ++ans;
    //     }
    //     temp >>= 1;
    // }
    // return ans;

    // Approach 3[O(no.of_SET-BITS)]
    int temp = n, ans = 0;
    while (temp != 0)
    {
        temp &= (temp - 1);
        ++ans;
    }
    return ans;
}

// Question 11
// 2 elements are unique and rest appear twice. output the 2 unique elements
void solution11(int arr[], int n)
{
    // Approach 1 [Time-O(nlog(n)), Space-O(n)]
    // map<int, int> mep;
    // for (int i = 0; i < n; i++)
    // {
    //     ++mep[arr[i]];
    // }

    // for (auto &a : mep)
    // {
    //     if (a.second == 1)
    //     {
    //         cout << a.first << endl;
    //     }
    // }

    // Approach 2[Time-O(n), Space-O(1)]
    int temp = 0;
    for (int i = 0; i < n; i++)
    {
        temp ^= arr[i];
    }
    // cout << temp << endl;

    int mask = 1;
    while (mask & temp != 1)
    {
        mask <<= 1;
    }
    // cout << mask << endl;

    int a = 0, b = 0;
    for (int i = 0; i < n; i++)
    {
        if (mask & arr[i])
        {
            a ^= arr[i];
        }
        else
        {
            b ^= arr[i];
        }
    }

    cout << a << " " << b << endl;
}

// Question 12
// Printing all the subsets of the array using bit masking(hint: when n <= 15/16)
void solution12(int arr[], int n)
{
    int subsets = (1 << n) - 1;

    for (int i = 0; i < subsets; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
            {
                cout << arr[j] << " ";
            }
        }
        cout << endl;
    }
}


int main()
{
    // Question 1
    // int a[] = {2, 1, 2, 5, 6, 5, 7, 7, 6};
    // cout << solution1(a, 9);

    // Property 1
    // int x = 2;
    // int y = 31;
    // swapXOR(x, y);

    // Question 2
    // cout << solution2(5) << endl;

    // Question 3
    // cout << solution3(2,4) << endl;

    // Question 4
    // solution4(12);
    // solution4(3);

    // Question 5
    // cout << solution5(13,0) << endl;
    // cout << solution5(13,1) << endl;

    // Question 6
    // cout << solution6(9, 3) << endl;
    // cout << solution6(9, 2) << endl;

    // Question 7
    // cout << solution7(9, 3) << endl;
    // cout << solution7(9, 2) << endl;

    // Question 8
    // cout << solution8(9) << endl;
    // cout << solution8(8) << endl;

    // Question 9
    // cout << solution9(9) << endl;
    // cout << solution9(8) << endl;

    // Question 10
    // cout << solution10(9) << endl;
    // cout << solution10(8) << endl;

    // Question 11
    // int a[] = {2, 1, 2, 5, 1, 4, 4, 7, 3, 3};
    // solution11(a, 10);

    // Question 12
    int a[] = {1, 2, 3};
    solution12(a, 3);

    return 0;
}