class Solution {
public:
    
    
    bool isRobotBounded(string instructions) {
        int visited[101][101];
        int x=0,y=0,dir=0;  //e(0),w(1),s(2),n(3)
        int cnt=4;
        while(cnt--){
            for(int i=0; i<instructions.length(); i++){
                int cmd=instructions[i];
                if(cmd=='G'){
                    if(dir==0) y+=1;
                    if(dir==1) x-=1;
                    if(dir==2) y-=1;
                    if(dir==3) x+=1;
                }
                if(cmd=='L'){
                    dir+=1;
                    if(dir>3) dir=0;
                }
                if(cmd=='R'){
                    dir-=1;
                    if(dir<0) dir=3;
                }
                
            }
            if(x==0&&y==0) return true;
            
        }
        return false;
    }
};
