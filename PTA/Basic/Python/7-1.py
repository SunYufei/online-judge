cm = int(input())
foot = cm // 30.48
inch = 12 * (cm / 30.48 - foot)
print(int(foot), int(inch))
