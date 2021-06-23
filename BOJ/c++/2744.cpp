//  Copyright © 2021 안주형. All rights reserved.
//  https://github.com/dkswnzz
//  https://www.acmicpc.net/problem/2744
//  BOJ2744 대소문자 바꾸기

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] >= 'a' && s[i] <= 'z') {   //소문자 인 경우
            s[i] = toupper(s[i]); //대문자로 변경
        } else {   //대문자인 경우
            s[i] = tolower(s[i]); //소문자로 변경
        }
    }
    cout << s;

}
