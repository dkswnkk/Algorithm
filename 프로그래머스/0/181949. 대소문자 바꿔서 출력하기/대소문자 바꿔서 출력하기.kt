fun main(args: Array<String>) {
    val s1 = readLine()!!
    var answer = ""

    for (char in s1) {
        if (char.isUpperCase()){
            answer += char.toLowerCase()
        } else {
            answer += char.toUpperCase()
        }
    }
    
    print(answer)
}