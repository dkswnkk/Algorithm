def solution(ineq, eq, n, m):
    
    if(ineq == '<' and eq == '='):
        return int(n <= m)
    if(ineq == '<' and eq == '!'):
        return int(n < m and n != m)
    if(ineq == '>' and eq == '='):
        return int(n >= m)
    if(ineq == '>' and eq == '!'):
        return int(n > m and n != m)