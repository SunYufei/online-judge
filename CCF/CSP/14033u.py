op = input()
ops = {}
for i in range(len(op)):
    if op[i + 1] == ':':
        ops[op[i]] = True
    elif op[i + 1] != ':' and op != ':':
        ops[op[i]] = False

n = int(input())

for idx in range(1, n + 1):
    ans = ''
    print("Case {0}: {1}".format(idx, ans))
