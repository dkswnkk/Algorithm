#include <string>
#include <vector>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int x_L = 3, y_L = 0;
    int x_R = 3, y_R = 2;
    
    for(int number:numbers){
        if(number==1||number==4||number==7){
            answer+='L';
            if(number==1) x_L = 0, y_L = 0;
            else if(number==4) x_L = 1, y_L=0;
            else if(number==7) x_L = 2, y_L = 0;
        }
        else if(number==3||number==6||number==9){
            answer+='R';
            if(number==3) x_R = 0, y_R = 2;
            else if(number==6) x_R = 1, y_R = 2;
            else if(number==9) x_R = 2, y_R = 2;
        }
        else{   //2, 5, 8, 0 일때
            if(number==2){
                int dist_L = abs(x_L-0) + abs(y_L-1);
                int dist_R = abs(x_R-0) + abs(y_R-1);
                if(dist_L<dist_R){  //왼쪽 엄지와의 거리가 더 짧을 때
                    x_L = 0, y_L = 1;
                    answer+='L';
                }
                else if(dist_L>dist_R){ //오른쪽 엄지와의 거리가 더 짧을 떄
                    x_R = 0, y_R = 1;
                    answer+='R';
                }
                else{   //거리가 같을 때
                    if(hand=="right"){  //오른손 잡이일떄
                        x_R = 0, y_R = 1;
                        answer+='R';
                    }
                    else{   //왼손 잡이일 때
                        x_L = 0, y_L = 1;
                        answer+='L';
                    }
                }
            }
            else if(number==5){
                int dist_L = abs(x_L-1) + abs(y_L-1);
                int dist_R = abs(x_R-1) + abs(y_R-1);
                if(dist_L<dist_R){  //왼쪽 엄지와의 거리가 더 짧을 때
                    x_L = 1, y_L = 1;
                    answer+='L';
                }
                else if(dist_L>dist_R){ //오른쪽 엄지와의 거리가 더 짧을 떄
                    x_R = 1, y_R = 1;
                    answer+='R';
                }
                else{   //거리가 같을 때
                    if(hand=="right"){  //오른손 잡이일떄
                        x_R = 1, y_R = 1;
                        answer+='R';
                    }
                    else{   //왼손 잡이일 때
                        x_L = 1, y_L = 1;
                        answer+='L';
                    }
                }
            }
            else if(number==8){
                int dist_L = abs(x_L-2) + abs(y_L-1);
                int dist_R = abs(x_R-2) + abs(y_R-1);
                if(dist_L<dist_R){  //왼쪽 엄지와의 거리가 더 짧을 때
                    x_L = 2, y_L = 1;
                    answer+='L';
                }
                else if(dist_L>dist_R){ //오른쪽 엄지와의 거리가 더 짧을 떄
                    x_R = 2, y_R = 1;
                    answer+='R';
                }
                else{   //거리가 같을 때
                    if(hand=="right"){  //오른손 잡이일떄
                        x_R = 2, y_R = 1;
                        answer+='R';
                    }
                    else{   //왼손 잡이일 때
                        x_L = 2, y_L = 1;
                        answer+='L';
                    }
                }
            }
            else if(number==0){
                int dist_L = abs(x_L-3) + abs(y_L-1);
                int dist_R = abs(x_R-3) + abs(y_R-1);
                if(dist_L<dist_R){  //왼쪽 엄지와의 거리가 더 짧을 때
                    x_L = 3, y_L = 1;
                    answer+='L';
                }
                else if(dist_L>dist_R){ //오른쪽 엄지와의 거리가 더 짧을 떄
                    x_R = 3, y_R = 1;
                    answer+='R';
                }
                else{   //거리가 같을 때
                    if(hand=="right"){  //오른손 잡이일떄
                        x_R = 3, y_R = 1;
                        answer+='R';
                    }
                    else{   //왼손 잡이일 때
                        x_L = 3, y_L = 1;
                        answer+='L';
                    }
                }
            }
        }
    }
    return answer;
}
