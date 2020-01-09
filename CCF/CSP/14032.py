n, m = map(int, input().split())

w = []

for i in range(1, n + 1):
    x1, y1, x2, y2 = map(int, input().split())
    w.append((x1, y1, x2, y2, i))

for _ in range(m):
    x, y = map(int, input().split())
    found = False
    for i, s in reversed(list(enumerate(w))):
        if x >= s[0] and x <= s[2] and y >= s[1] and y <= s[3]:
            print(s[4])
            last = w[i]
            for j in range(i, n - 1):
                w[j] = w[j + 1]
            w[-1] = last
            found = True
            break
    if not found:
        print("IGNORED")
