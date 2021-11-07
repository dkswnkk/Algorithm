class Solution {
public:
  string multiply(string num1, string num2) {
    if(num1 == "0" || num2 == "0") return "0";

    vector<int> v(num1.length() + num2.length(), 0);
    for(int i = num1.length()-1; i >= 0; i--){
      for(int k = num2.length()-1; k >= 0; k--){
        int mul = (num1[i]-'0') * (num2[k]-'0') + v[i+k+1];
        v[i+k+1] = mul % 10;
        v[i+k] += mul / 10;
      }
    }
      
    string result = "";
      
    for(int i = 0; i <v.size(); i++){
        if(v[i]==0&&i==0) continue;
      result += v[i]+'0';
    }

    return result;
  }
};
