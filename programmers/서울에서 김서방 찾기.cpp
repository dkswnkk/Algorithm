#include <string>
#include <vector>


using namespace std;

string solution(vector<string> seoul) {
    string answer= "";
    answer = "김서방은 ";
    
    for(int i=0; i<seoul.size(); i++){
       if(seoul[i]=="kim"){          
            answer+= to_string(i);
            break;
        }

    answer+="에 있다";
    return answer;
}
