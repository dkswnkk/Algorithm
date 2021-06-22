//  Copyright © 2021 안주형. All rights reserved.
//  https://github.com/dkswnzz
//  https://www.acmicpc.net/problem/10823
//  BOJ10823 더하기2

#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s, temp;
    int ans = 0;
    while (getline(cin, s)) {
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != ',') {
                temp += s[i];
            } else {
                ans += stoi(temp);
                temp.clear();

            }
        }
    }
    ans += stoi(temp);
    cout << ans;

}
