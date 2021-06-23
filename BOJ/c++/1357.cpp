//  Copyright © 2021 안주형. All rights reserved.
//  https://github.com/dkswnzz
//  https://www.acmicpc.net/problem/1357
//  BOJ1357 뒤집힌 덧셈

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string x, y, temp;
    cin >> x >> y;

    reverse(x.begin(), x.end());
    reverse(y.begin(), y.end());
    temp = to_string(stoi(x) + stoi(y));
    reverse(temp.begin(), temp.end());
    cout << stoi(temp);

}
