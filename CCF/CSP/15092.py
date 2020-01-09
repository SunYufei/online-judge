import datetime

y = input()
d = int(input()) - 1

date = datetime.datetime.strptime('{0}0101'.format(y), '%Y%m%d')
new_date = date + datetime.timedelta(days=d)
m = new_date.strftime("%m")
dd = new_date.strftime("%d")
print(int(m))
print(int(dd))
