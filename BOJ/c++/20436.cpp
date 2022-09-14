#include <iostream>
using namespace std;

int map[3][10];

string top = "qwertyuiop";
string middle = "asdfghjkl";
string bottom = "zxcvbnm";

struct Info{
    int r;
    int c;
    char hand;
};

Info l, r;

Info find_coor(char key){
    int _r = 0, _c = 0;
    char hand;
    for(int i=0; i<top.length(); i++){
        if(top[i] == key){
            _r = 0, _c = i;
            if(i<=4) hand = 'l';
            else hand = 'r';
        }
    }
    for(int i=0; i<middle.length(); i++){
        if(middle[i] == key){
            _r = 1, _c = i;
            if(i <= 4) hand = 'l';
            else hand = 'r';
        }
    }
    for(int i=0; i<bottom.length(); i++){
        if(bottom[i] == key){
            _r = 2, _c = i;
            if(i <= 3) hand = 'l';
            else hand = 'r';
        }
    }
    return {_r, _c, hand};
}

int find_dist(char key){
    Info key_coor = find_coor(key);
    int dist = 0;
    if(key_coor.hand == 'l'){
        dist = abs(l.r - key_coor.r) + abs(l.c - key_coor.c);
        l.r = key_coor.r;
        l.c = key_coor.c;
    }
    if(key_coor.hand == 'r'){
        dist = abs(r.r - key_coor.r) + abs(r.c - key_coor.c);
        r.r = key_coor.r;
        r.c = key_coor.c;
    }
    return dist;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    char left, right; cin>>left>>right;
    string s; cin>>s;
    
    l = find_coor(left);
    r = find_coor(right);
    int ans = 0;
    for(char key: s) ans += find_dist(key);
    
    cout<<ans+s.length();
    
    
}
