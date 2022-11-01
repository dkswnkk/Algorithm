#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    string s, ans; cin>>s;
    int len = s.length();
    bool flag = true;
    
    if(s.front() == '_' || s.back() == '_' || isupper(s.front())){
        flag = false;
    }
    else if(s.find('_') != string::npos)
        for(int i=0; i<len; i++){   // c++ 검사
            if(isupper(s[i]) && s[i-1] != '_'){
                flag = false;
                break;
            }
            else if(s[i]=='_'){
                if(isupper(s[i+1])){
                    flag = false;
                    break;
                }
                if(s[i-1] == '_' || s[i+1] == '_'){
                    flag = false;
                    break;
                }
                s[i+1] = toupper(s[i+1]);
            }
            else ans += s[i];
        }
    else{
        for(int i=0; i<len; i++){   // java 검사
            if(isupper(s[i])){
                ans += '_';
                ans += tolower(s[i]);
            }
            else{
                ans += s[i];
            }
        }
    }
    if(!flag) cout<<"Error!";
    else cout<<ans;
}

/*
 //맨 뒤 문자가 '_' 이면 에러
 asd_
 Error!

 //맨 앞 문자가 '_' 이면 에러
 _asd
 Error!

 //'_' 연속 두개면 에러
 as__asd
 Error!

 //맨 앞 문자가 대문자면 에러
 Aasd
 Error!

 //대문자와 '_'가 혼종이면 에러
 asdAasd_asd
 Error!
     
 //소문자만 입력 될 경우 정상
 fadfadfadsf
 fadfadfadsf

 // 대문자 연속일 경우 정상
 asdasdASDASD
 asdasd_a_s_d_a_s_d
 */
