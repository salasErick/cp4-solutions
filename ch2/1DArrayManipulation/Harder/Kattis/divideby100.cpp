#include <bits/stdc++.h>
#include <string>

using namespace std;


// I don't know why it is wrong

int countZeros(const string &n) {
    int zeros = 0;
    for(int i = 0; i < n.length(); i++) {
        if(n[i] == '0')
            zeros++;
    }
    return zeros;

}

string trimZeros(const string &n) {
    size_t decimalPos = n.find('.');
    if(decimalPos == string::npos) {
        return n;
    }
    size_t lastNonZero = n.find_last_not_of('0');
    if(lastNonZero == decimalPos) {
        return n.substr(0, decimalPos);
    }
    return n.substr(0, lastNonZero + 1);
}

int main() {
    string n, m;
    string result = "";
    cin >> n >> m;
    if(n.length() > m.length()) {
        int zeros = countZeros(m);
        result = n.insert(n.length() - zeros, 1, '.');
    } else {
        int zeros = countZeros(m);
        result.append(zeros, '0');
        result += n;
        result.insert(result.begin()+1, 1, '.');
    }
    result = trimZeros(result);
    cout << result << endl;
    return 0;
}
