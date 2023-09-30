N, K  = map(int, input().split())

arr = [i for i in range(1, N+1)]

answer = []
index = K - 1

for i in range (0, N):
    answer.append(arr[index])
    arr.pop(index)
    if(len(arr) == 0):
        break
    index = (index + K - 1) % len(arr)

print("<", ", ".join(map(str, answer)), ">", sep='')