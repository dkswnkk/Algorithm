class Solution {
public:
    int sum=0;
    
    int roman_to_int(char c1,char c2){
        bool flag = true;
        if(c1=='I'){
            if(c2=='V'){
                sum+=4;
                flag = false;
            }
            else if(c2 =='X'){
                sum+=9;
                flag = false;
            }
            else sum+=1;
        }
        else if(c1=='V') sum+= 5;
        else if(c1=='C'){
            if(c2=='D'){
                sum+=400;
                flag = false;
            }
            else if(c2 =='M'){
                sum+=900;
                flag = false;
            }
            else sum+=100;
        }
        else if(c1=='X'){
            if(c2=='L'){
                sum+=40;
                flag = false;
            }
            else if(c2 =='C'){
                sum+=90;
                flag = false;
            }
            else sum+=10;
        }
        else if(c1=='L') sum+=50;
        else if(c1=='D') sum+=500;
        else if(c1=='M') sum+=1000;
        
        return flag;
    }
    
    int romanToInt(string s) {
        for(int i=0; i<s.length(); i++){
            if(!roman_to_int(s[i],s[i+1])) i++;
            
        }
        return sum;
    }
};
