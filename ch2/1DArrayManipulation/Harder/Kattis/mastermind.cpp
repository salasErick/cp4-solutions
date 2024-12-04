#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

/* I thought about computing first r and then s.
 * Computing r was straight forward but s is somewhat tricky.
 * I encountered some problems trying to get it.
 * The first one was that I was evaluating the characters more than once
 * and I had to separate between what letters I had already processed
 * and the ones that were left. 
 * To do so I separated them into two groups.
 */

int main() {
    unordered_map<char, int> code, guess;
    int n, r = 0, s = 0;
    cin >> n;
    string maker, breaker;
    cin >> maker >> breaker;

    // get r
    for(int i = 0; i < n; i++) {
        if(maker[i] == breaker[i])
            r++;
        else {
            code[maker[i]]++;
            guess[breaker[i]]++;
        }
    }

    // get s
    for(auto &val : guess) {
        char ch = val.first;
        s += min(val.second, code[ch]);
    }
    
    cout << r << " " << s << endl;
    return 0;
}
