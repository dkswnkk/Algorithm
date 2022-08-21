def backtracking(idx, cal, result, flag):
    if idx == N:
        if result == 0:
            ans.append(cal)
        elif flag:
            if eval(cal.replace(' ', '')) == 0:
                ans.append(cal)
        return

    backtracking(idx + 1, cal + ' ' + str(idx + 1), 1e9, True)
    backtracking(idx + 1, cal + '+' + str(idx + 1), result + (idx + 1), flag)
    backtracking(idx + 1, cal + '-' + str(idx + 1), result - (idx + 1), flag)


T = int(input())
ans = []
for i in range(T):
    N = int(input())
    backtracking(1, "1", 1, False)
    ans.sort()
    for k in range(0, len(ans)):
        print(ans[k])
    ans.clear()
    print()
