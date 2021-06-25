//  Copyright © 2021 안주형. All rights reserved.
//  https://github.com/dkswnzz
//  https://www.acmicpc.net/problem/2789
//  BOJ2789 유학 금지

#include <iostream>

using namespace std;

bool check(char c) {
    if (c == 'C' || c == 'A' || c == 'M'|| c == 'B' || c == 'R' || c == 'I' || c == 'D' || c == 'G' ||
        c == 'E')
        return false;
    else return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;

    for (int i = 0; i < s.length(); i++) {
        if (Check(s[i])) cout << s[i];
    }
}

