import json

n, m = map(int, input().split())
json_str = ''
for _ in range(n):
    json_str += input()
obj = json.loads(json_str)


for _ in range(m):
    c = input().split('.')
    try:
        t = eval('obj' + ''.join(['[' + repr(x) + ']' for x in c]))
        if type(t) == str:
            print('STRING', t)
        elif type(t) == dict:
            print('OBJECT')
    except Exception:
        print('NOTEXIST')
