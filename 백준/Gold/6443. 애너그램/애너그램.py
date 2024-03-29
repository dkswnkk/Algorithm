import sys

N = int(sys.stdin.readline().strip())

def backtracking(word, current, visited):
    if len(current) == len(word):
        answer.add(current)
        return
    for i in range(0, len(word)):
        temp = current + word[i]
        if (visited[i] or (temp in duplicate)):
            continue
        visited[i] = True
        duplicate.add(temp)
        backtracking(word, temp, visited)
        visited[i] = False

answer = set()
for _ in range(N):
    word = sys.stdin.readline().strip()
    visited = [False] * len(word)
    duplicate = set()
    backtracking(word, "", visited)

answer = sorted(answer, key=lambda x: (len(x), x))
for ans in answer:
    print(ans)