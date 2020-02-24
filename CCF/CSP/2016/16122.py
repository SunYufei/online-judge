def t(s: int) -> int:
    if s <= 3500:
        return s
    else:
        ans = s
        a = s - 3500
        if a <= 1500:
            ans -= a * 0.03
        elif a > 1500 and a <= 4500:
            ans -= 45
            a -= 1500
            ans -= a * 0.1
        elif a > 4500 and a <= 9000:
            ans -= 345
            a -= 4500
            ans -= a * 0.2
        elif a > 9000 and a <= 35000:
            ans -= 1245
            a -= 9000
            ans -= a * 0.25
        elif a > 35000 and a <= 55000:
            ans -= 7745
            a -= 35000
            ans -= a * 0.3
        elif a > 55000 and a <= 80000:
            ans -= 13745
            a -= 55000
            ans -= a * 0.35
        else:
            ans -= 22495
            a -= 80000
            ans -= a * 0.45
        return ans

# 生成一个字典用于查询
s = {}

for i in range(0, 154500, 100):
    s[t(i)] = i

n = int(input())
print(s[n])
