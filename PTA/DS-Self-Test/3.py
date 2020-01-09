from collections import deque

n, m = map(int, input().split())
d = deque(map(int, input().split()), n)
d.rotate(m)

print(' '.join(map(str, d)))
