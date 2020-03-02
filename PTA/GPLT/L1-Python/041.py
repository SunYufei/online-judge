a = list(map(int, input().split()))
for i, item in enumerate(a):
    if item == 250:
        print(i+1)
        break
