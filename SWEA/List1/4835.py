"""
for문을 돌면서 현재 구간값에 새로 구간에 해당하는 값을 더하고 구간에 해당되지 않는
값을 빼며 구간합을 구한다.
"""

t = int(input())

for tc in range(1, t+1) :
    n, m = list(map(int, input().split()))
    numList = list(map(int, input().split()))
    minValue = sum(numList[0:m])
    maxValue = sum(numList[0:m])
    value = sum(numList[0:m])

    for i in range(m, n) :
        value = value+numList[i]-numList[i-m]
        minValue = min(value, minValue)
        maxValue = max(value, maxValue)
        
    print("#{} {}".format(tc, maxValue-minValue))