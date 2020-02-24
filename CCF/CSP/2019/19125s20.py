U = [314882150829468584,
     427197303358170108,
     1022292690726729920,
     1698479428772363217,
     2006101093849356424]


def f(x):
    return (x % 2009731336725594113) % 2019


n, q = map(int, input().split())

A = [i for i in range(n + 1)]
FA = [f(i) for i in A]

for _ in range(q):
    l, r = map(int, input().split())
    s = sum(FA[l:r + 1])
    print(s)
    t = s % 5
    for i in range(l, r + 1):
        A[i] = A[i] * U[t]
        FA[i] = f(A[i])
