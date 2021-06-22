//  Copyright © 2021 안주형. All rights reserved.
//  https://github.com/dkswnzz
//  https://www.acmicpc.net/problem/10820
//  BOJ10820

#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s;

    while (getline(cin, s)) {
        if (s.length() == 0) break; //입력이 없을때 종료
        int lower=0, upper = 0, number=0, empty = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] >= 'A' && s[i] <= 'Z') upper++;
            else if (s[i] >= 'a' && s[i] <= 'z') lower++;
            else if (s[i] >= '0' && s[i] <= '9') number++;
            else if (s[i] == ' ') empty++;
        }
        cout << lower << ' ' << upper << ' ' << number << ' ' << empty << '\n';
    }
}
