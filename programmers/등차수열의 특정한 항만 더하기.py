def solution(a, d, included):
    current = 0
    answer = 0
    for index, flag in enumerate(included):
        if(flag):
            answer += a + index * d
            
    return answer