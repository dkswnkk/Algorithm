class Solution {
    fun solution(str1: String, str2: String): String {
        var answer: String = ""
        
        for(i in str1.indices) {
            answer += str1[i]
            answer += str2[i]
        }
        
        return answer
    }
}