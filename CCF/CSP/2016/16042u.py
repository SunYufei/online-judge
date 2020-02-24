base = []
block = []

for _ in range(15):
    base.append(list(map(int, input().split())))

for _ in range(4):
    block.append(list(map(int, input().split())))

pos = int(input())

for i in range(15):
    print(' '.join(map(str, base[i])))
