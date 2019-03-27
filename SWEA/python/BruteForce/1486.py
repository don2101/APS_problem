# 1. 부분 집합 문제.
# 2. 각 사람이 포함되냐, 안되냐의 문제
# 3. 모든 부분 집합을 조사하며 키를 더한다.
# 4. 더한 값이 기존 값 보다 작고, b 보다 크면 갱신


t = int(input())
tc = 1

while tc <= t:
    ans = 9999999
    n, b = (map(int, input().split()))
    height = list(map(int, input().split()))
    
    for i in range(1<<n):
        height_sum = 0
        find = True
        
        for j in range(n):
            if i & 1<<j:
                height_sum += height[j]
                if height_sum > ans:
                    find = False
                    break
        if find:
            if height_sum >= b and height_sum < ans:
                if height_sum == b:
                    ans = height_sum
                    break
                ans = height_sum
        
    print("#{} {}".format(tc, ans-b))
    tc += 1
    