#%%
n = input()
m = [0] * 10
for i in n:
    m[int(i)] += 1
for i in range(10):
    if m[i] != 0:
        print(':'.join(map(str, [i, m[i]])))