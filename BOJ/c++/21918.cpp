#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N, M; cin>>N>>M;
    int bulb[4001]={0, };
    
    for(int i=1; i<=N; i++){
        cin>>bulb[i];
    }
    for(int i=0; i<M; i++){
        int a,b,c; cin>>a>>b>>c;
        
        if(a==1) bulb[b]=c; //1번 명령어
        
        else if(a==2){  //2번 명령어
            for(int i=b; i<=c; i++){
                if(!bulb[i]) bulb[i]=1; //꺼져있으면 켠다.
                else bulb[i]=0; //켜져잇으면 끈다.
            }
        }
        
        else if(a==3){  //3번 명령어(l~r까지 전구를 끈다.)
            for(int i=b; i<=c; i++){
                bulb[i]=0;
            }
        }
        
        else if(a==4){  //4번 명령어(l~r까지 전구를 켠다.)
            for(int i=b; i<=c; i++){
                bulb[i]=1;
            }
        }
    }
    for(int i=1; i<=N; i++){
        cout<<bulb[i]<<' ';
    }
}
