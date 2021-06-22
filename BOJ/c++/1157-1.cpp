#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;
    char ans;
    map<char, int> m;
    bool flag = false;    //가장 많이 사된 알파벳이 여러개인 경우를 체크

    for (int i = 0; i < s.length(); i++) {
        s[i] = toupper(s[i]); //대문자로 변경
        m[s[i]]++;
    }
    int max = 0;

    for (auto i = m.begin(); i != m.end(); i++) { //제일 갯수가 많은 알파벳이 몇개인지 검사.
        if (max <= i->second) {
            max = i->second;
            ans = i->first;
        }
    }

    for (auto i = m.begin(); i != m.end(); i++) {
        if (i->second == max && ans != i->first) { //갯수가 같은데 다른 알파벳인 경우
            flag = true;
            break;
        }
    }
    if (flag) cout << "?";
    else cout << ans;
}
