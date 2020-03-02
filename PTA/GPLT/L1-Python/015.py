n, c = input().split()
n = int(n)
if n / 2 - int(n / 2) >= 0.5:
    h = int(n / 2) + 1
else:
    h = int(n / 2)
for i in range(h):
    print(c * n)
