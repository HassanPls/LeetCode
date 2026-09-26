#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        int opened = 0;
        map<string, string> dic;
        for (int i = 0; i < knowledge.size(); i++)
        {
            dic[knowledge[i][0]] = knowledge[i][1];
        }

        string response = "";
        string key = "";

        for (int i = 0; i < s.size(); i++)
        {
            char c = s[i];

            if (c != '(' && c != ')') key = key + c;

            if (c == '(') {
                opened = 1;
                response.append(key);
                key = "";
            } else if (c == ')') {
                opened = 0;

                if (dic.count(key)) {
                    response.append(dic[key]);
                } else {
                    response.append("?");
                }

                key = "";
            } 
        }

        response.append(key);
        
        return response;
    }
};