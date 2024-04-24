#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Solution()
    string intToRoman(int num)
    {
        char *c[4][10] = {
            {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},
            {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
            {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
            {"", "M", "MM", "MMM"}};
        string roman_number;
        roman_number.append(c[3][num / 1000 % 10]);
        roman_number.append(c[2][num / 100 % 10]);
        roman_number.append(c[1][num / 10 % 10]);
        roman_number.append(c[0][num % 10]);

        return roman_number;
    }
};
int main()
{
    Solution solution = Solution();
    //    solutio
    string result = solution.intToRoman(16080);//MDCLXXX
    cout<<result<<endl;
}