s = input()


def check(l, r):
    while l < r:
        if s[l] == s[r]:
            l, r = l + 1, r - 1
        else:
            return False
    return True


ans = True
l, r = 0, len(s) - 1
while l < r:
    if s[l] == s[r]:
        l, r = l + 1, r - 1
    else:
        if check(l + 1, r) or check(l, r - 1):
            break
        else:
            ans = False
            break

print('true' if ans else 'false')
