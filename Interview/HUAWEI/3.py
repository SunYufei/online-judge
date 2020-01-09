inputs = input().split(';')
equation = inputs[0].split(',')
nums = {}
ans = inputs[2]

for i in inputs[1].split(','):
    nums[i.split('=')[0]] = i.split('=')[1]

count = 0
while count < len(equation):
    for i in equation:
        i = i.replace('{', '')
        i = i.replace('}', '')
        for k in nums:
            if k in i and '[' in k:
                i = i.replace(k, str(nums[k]))
        tmp = i.split('=')
        if '[' not in tmp[1]:
            nums[tmp[0]] = int(eval(tmp[1]))
            count += 1

print(nums[ans])
