class Solution {
    fun solution(a: Int, b: Int): Int {
        val ab = "$a$b".toInt()
        val ab2 = 2 * a.toInt() * b.toInt()
        
        return maxOf(ab, ab2)
    }
}