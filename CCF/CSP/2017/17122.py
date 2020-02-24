from queue import Queue
n, k = map(int, input().split())
q = []
for i in range(1, n + 1):
    q.append(i)
num = 1
while len(q) > 1:
    t = q.pop(0)
    if not (num % k == 0 or num % 10 == k):
        q.append(t)
    num += 1
print(q[0])
