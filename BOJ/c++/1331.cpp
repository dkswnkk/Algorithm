#include <iostream>
using namespace std;


int map[6][6];
int visited[6][6];

int dx[8] = {-1,-1,1,1,-2,-2,2,2};
int dy[8] = {-2,2,-2,2,-1,1,-1,1};


char check_alpha(char c){
    if(c=='A') return 0;
    if(c=='B') return 1;
    if(c=='C') return 2;
    if(c=='D') return 3;
    if(c=='E') return 4;
    if(c=='F') return 5;
    return 0;
}

int check_num(int i){
    if(i==6) return 0;
    if(i==5) return 1;
    if(i==4) return 2;
    if(i==3) return 3;
    if(i==2) return 4;
    if(i==1) return 5;
    return 0;
}

bool valid(int before_y, int before_x, int now_y, int now_x){
    for(int i=0; i<8; i++){
        int ny = before_y + dy[i];
        int nx = before_x + dx[i];
        if(nx==now_x && ny==now_y) return true;
    }
    return false;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int start_y, start_x;
    for(int i=0; i<36; i++){
        string inp; cin>>inp;
        
        int before_y, before_x;
        char c = inp[0];
        int y = check_num(inp[1]-'0');
        int x = check_alpha(c);
        
        if(i==0){
            before_y = y;
            before_x = x;
            start_y = y;
            start_x = x;
            continue;
        }
        
        if(i==35){
            if(visited[y][x]||!valid(start_y, start_x, y,x)){
                cout<<"Invalid";
                return 0;
            }
        }
        
        if(!visited[y][x]){
            if(valid(before_y, before_x, y,x)){
                visited[y][x] = 1;
                before_y = y;
                before_x = x;
            }
            else{
                cout<<"Invalid";
                return 0;
            }
        }
        else{
            cout<<"Invalid";
            return 0;
        }
    }
    cout<<"Valid";
}
