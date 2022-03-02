class Solution {
public:
    int addDigits(int num) {
        int temp1=0, temp2=0, ans=num;
        while(true){
            while(num>9){
                temp1 = num%10;
                temp2 = num/10;
                ans = temp1 + temp2;
                num = ans;
            }
            if(num<10){
                num = ans;
                return num;
            }
        }
        
    }
};
