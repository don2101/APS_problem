"""
조건에 대해 연료를 소비하면서 도달 가능 여부와 연료 충전 횟수를 구한다.
"""


t = int(input())

for tc in range(1, t+1) :
    k, n, m = list(map(int, input().split()))
    fuel = list(map(int, input().split()))
    
    hasFuel = 0
    remain = k
    i = 0
    ans = 0
    while(True) :
        i += 1
        remain -= 1
        if i == n :
            break
        if i in fuel :
            hasFuel = i
        if remain == 0 and hasFuel > 0 :
            i = hasFuel
            hasFuel = 0
            remain = k
            ans += 1
        elif remain == 0 and hasFuel == 0 :
            ans = 0
            break

    print("#{} {}".format(tc, ans))
    
        
    
    