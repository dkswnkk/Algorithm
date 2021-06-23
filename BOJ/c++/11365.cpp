//  Copyright © 2021 안주형. All rights reserved.
//  https://github.com/dkswnzz
//  https://www.acmicpc.net/problem/11365
//  BOJ11365 !밀비 급일

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s;
    while (getline(cin, s)) {
        if (s == "END") break;
        reverse(s.begin(), s.end());
        cout << s << "\n";
    }

}

