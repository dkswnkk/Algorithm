//  Copyright © 2021 안주형. All rights reserved.
//  https://github.com/dkswnzz
//  https://www.acmicpc.net/problem/2495
//  BOJ2495 연속구간

#include <iostream>

using namespace std;


int cnt = 1, max_cnt = 0;

void check(string s) {
    for (int i = 0; i < s.length() - 1; i++) {
        for (int k = i + 1; k < s.length(); k++) {
            if (s[i] == s[k]) cnt++;
            else if (s[i] != s[k]) break;
        }
        if (cnt >= max_cnt) max_cnt = cnt;
        cnt = 1;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    for (int i = 0; i < 3; i++) {
        string s;
        cin >> s;
        check(s);
        cout << max_cnt << "\n";
        max_cnt=0;
    }
}
