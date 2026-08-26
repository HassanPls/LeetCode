#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int i = 0, j = 0;
        int uns = 0;
        int minLenght = s.size() + 1;
        string sMin = "";

        while (j < s.size())
        {
            if (s[j] == '1') uns++;

            while (uns == k)
            {
                int length = j - i + 1;
                string nowS = s.substr(i, length);
                
                if (length < minLenght || (length == minLenght && nowS < sMin)) {
                    minLenght = length;
                    sMin = nowS;
                }

                if (s[i] == '1') uns--;
                i++;
            }

            j++;
        }
        
        return sMin;
    }
};