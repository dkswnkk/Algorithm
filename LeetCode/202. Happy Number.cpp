class Solution {
public:
    bool isHappy(int n) {
        string s;
        s = to_string(n);
        while(true){
            unsigned long long temp = 0;
            for(int i=0; i<s.length(); i++){
                temp += pow(s[i]-'0',2);
            }
            if(temp==1||temp==7) return true;
            if(temp<10&&temp!=1) return false;
            s = to_string(temp);
        }
    }
};
