l = list(map(int, input().split()))
score = 0
current = 1
for i in l:
    if i == 0:
        break
    elif i == 1:
        current = 1
        score += current
    else:
        if current == 1:
            current = 2
        else:
            current += 2
        score += current

print(score)
