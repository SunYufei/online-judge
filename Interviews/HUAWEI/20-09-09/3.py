n = int(input())

tree = [[]] * (n + 10)

for _ in range(n):
    idx, w, l, r = map(int, input().split())
    tree[idx] = [w, l, r]
