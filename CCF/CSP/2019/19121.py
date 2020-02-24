n = int(input())

count = 0
ans = [0] * 4
current = 0

while count < n:
    current += 1
    if ('7' not in str(current)) and (current % 7 != 0):
        count += 1
    else:
        ans[current % 4 - 1] += 1

for i in ans:
    print(i)
