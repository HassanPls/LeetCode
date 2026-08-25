/* Given a string text, you want to use the characters of text to form as many instances of the word "balloon" as possible.

You can use each character in text at most once. Return the maximum number of instances that can be formed. */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxNumberOfBalloons(string text)
    {
        unordered_map<char, int> ballon;
        for (size_t i = 0; i < text.size(); i++)
        {
            ballon[text[i]]++;
        }

        int total = 0;
        while (ballon['b'] > 0 && ballon['a'] > 0 && ballon['l'] > 1 && ballon['o'] > 1 && ballon['n'] > 0)
        {
            ballon['b']--;
            ballon['a']--;
            ballon['l'] -= 2;
            ballon['o'] -= 2;
            ballon['n']--;
            total++;
        }

        return total;
    }
};