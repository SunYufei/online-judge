n=int(input())
r=list(map(int,input().split()))

def check(t):
    for i in range(len(t)-1):
        if t[i]>t[i+1]:
            return False
    return True


def right():
    count = 0
    t = r.copy()

    while not check(t):
        for i in range(n - 1):
            if t[i] > t[i+1]:
                t.append(t[i])
                t.pop(i)
                i-=1
                count+=1
    return count

def left():
    count=0
    t=r.copy()
    while not check(t):
        for i in range(n-1):
            if t[i]>t[i+1]:
                tt=[t[i+1]]
                t.pop(i+1)
                tt.extend(t)
                t=tt.copy()
                count+=1
    return count

print(min(left(),right()))