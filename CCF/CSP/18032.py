n, L, t = map(int, input().split())
a = list(map(int, input().split()))
pos = [True] * n


def next_step():
    for i in range(n):
        if pos[i]:
            a[i] += 1
        else:
            a[i] -= 1
    for i in range(n):
        if a[i] == 0 and pos[i] is False:
            pos[i] = True
        elif a[i] == L and pos[i] is True:
            pos[i] = False
    for i in range(n - 1):
        for j in range(i + 1, n):
            if a[i] == a[j] and pos[i] != pos[j]:
                pos[i] = not pos[i]
                pos[j] = not pos[j]


for _ in range(t):
    next_step()

print(' '.join(map(str, a)))
