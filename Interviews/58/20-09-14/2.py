s = input()

res = str()

l, r = 0, 0
while l < len(s) and r < len(s):
    if r - l > len(res):
        res = s[l:r + 1]
    if s[r] not in '5678':
        l = r + 1
    r += 1

print(res)
