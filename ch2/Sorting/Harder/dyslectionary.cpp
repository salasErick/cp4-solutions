#include <algorithm>
#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

int getMaxLength(const vector<string>& dictionary) {
    int maxLength = 0;
    for (const string& word : dictionary) {
        if (word.size() > maxLength) {
            maxLength = word.size();
        }
    }
    return maxLength;
}

int main() {
    bool flag = true;
    while(true) {
        int max = 0;
        vector<string> dictionary;
        while(true) {
            string line = "";
            getline(cin, line);
            if(cin.eof()) {
                flag = false;
                break;
            }
            if(line.empty())
                break;
            reverse(line.begin(), line.end());
            dictionary.push_back(line);
        }
        if(dictionary.empty() && cin.eof()) {
            break;
        }
        sort(dictionary.begin(), dictionary.end());
        max = getMaxLength(dictionary);
        for(string line : dictionary) {
            reverse(line.begin(), line.end());
            printf("%*s\n", max, line.c_str());
        }
        if(!cin.eof())
            printf("\n");
    }
}
