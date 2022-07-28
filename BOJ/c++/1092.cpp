#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    vector<int> crane, box;
    
    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        int n; cin >> n;
        crane.push_back(n);
    }
    
    int K; cin>>K;
    for (int i = 0; i < K; i++) {
        int k; cin >> k;
        box.push_back(k);
    }
    
    sort(crane.begin(), crane.end(), greater<>());
    sort(box.begin(), box.end(), greater<>());
    
    int cnt = 0;
    // 불가능한 경우
    if (crane.front() < box.front()) {
        cout << -1;
        return 0;
    }
    
    while (!box.empty()) {
        cnt++;
        // 크레인 가장 큰 무게 부터
        for (int i = 0; i<crane.size(); i++) {
            // 상자 가장 큰 무게 부터
            for (int k = 0;  k< box.size(); k++) {
                // 옮길 수 있으면 삭제하고 다음 크레인으로
                if (crane[i] >= box[k]) {
                    box.erase(box.begin() + k);
                    break;
                }
            }
        }
    }
    cout << cnt;
}
