#include <iostream>
#include <deque>
using namespace std;

int N, K, ans;
int up = 0, down = N-1; // 올리는 칸, 내리는 칸
deque<pair<int,int>>dq; // {내구도, 로봇 유무}

/*
 언제든지 로봇이 내리는 위치에 도달하면 그 즉시 내린다.
 */
void getoff(){
    if(dq[N-1].second){
        dq[N-1].second = 0;
    }
}

/*
 벨트가 각 칸 위에 있는 로봇과 함께 한 칸 회전한다.
 */
void rotation(){
    pair<int, bool> back = dq.back();
    dq.pop_back();
    dq.push_front(back);
    getoff();
}

/*
 가장 먼저 벨트에 올라간 로봇부터, 벨트가 회전하는 방향으로 한 칸 이동할 수 있다면 이동한다. 만약 이동할 수 없다면 가만히 있는다.
 로봇이 이동하기 위해서는 이동하려는 칸에 로봇이 없으며, 그 칸의 내구도가 1 이상 남아 있어야 한다.
 */
void move(){
    for(int i=(2*N)-1; i>=0; i--){
        int next = i + 1;
        if(i == (2*N)-1) next = 0;
        if(!dq[next].second&& dq[next].first >= 1 && dq[i].second){
            dq[next].first--;
            dq[next].second = 1;
            dq[i].second = 0;
        }
        getoff();
    }
}

/*
 올리는 위치에 있는 칸의 내구도가 0이 아니면 올리는 위치에 로봇을 올린다.
 */
void upload(){
    if(dq[up].first > 0 && dq[up].second == 0){
        dq[up].first--;
        dq[up].second = 1;
    }
}

/*
 내구도가 0인 칸의 개수가 K개 이상이라면 과정을 종료한다. 그렇지 않다면 1번으로 돌아간다.
 */
bool check(){
    int cnt = 0;
    for(int i=0; i<2*N; i++){
        if(dq[i].first == 0) cnt++;
    }
    if(cnt >= K) return false;
    return true;
}

void simulation(){
    bool flag = true;
    while(flag){
        rotation();
        move();
        upload();
        if(!check()) flag = false;
        ans++;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>N>>K;
    
    for(int i=0; i<2*N; i++){
        int inp; cin>>inp;
        dq.push_back({inp, 0});
    }
    simulation();
    cout<<ans;
}
