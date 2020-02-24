n = int(input()) / 10
ans = 0

while n >= 5:
    n -= 5
    ans += 7
while n >= 3:
    n -= 3
    ans += 4
ans += n

print(int(ans))
