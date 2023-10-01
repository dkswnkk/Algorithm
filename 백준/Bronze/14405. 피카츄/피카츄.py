s = input()

s = s.replace('pi', '*')
s = s.replace('ka', '*')
s = s.replace('chu', '*')

flag = True
for i in s:
    if i != '*':
        flag = False
        break

if flag:
    print('YES')
else:
    print('NO')