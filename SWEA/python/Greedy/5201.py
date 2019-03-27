# 1. Greedy 접근방식
# 2. 남은 트럭이 있고, 남은 컨테이너가 있을 동안,
# 3. 최대 용량 트럭을 선택하고, 최대 크기 컨테이너중 트럭에 담을 수 있는 컨테이너를 선택
# 4. 선택된 트럭과 컨테이너를 표시하고 크기를 ans에 추가


t = int(input())
tc = 1


while tc <= t:
    ans = 0
    n, m = (map(int, input().split()))
    container = list(map(int, input().split()))
    truck = list(map(int, input().split()))
    used = [False for _ in range(m)]
    moved = [False for _ in range(n)]
    remain_m = m
    remain_n = n    
    
    while remain_m > 0 and remain_n > 0:
        max_value = 0
        max_idx = -1
        for i in range(m):
            if not used[i] and max_value < truck[i]:
                max_value = truck[i]
                max_idx = i
        
        used[max_idx] = True
        remain_m -= 1
        
        max_container = 0
        max_idx = -1
        for i in range(n):
            if not moved[i] and max_container < container[i] and max_value >= container[i] :
                max_container = container[i]
                max_idx = i
        
        moved[max_idx] = True
        remain_n -= 1
        ans += max_container
        
    
    print("#{} {}".format(tc, ans))
    tc += 1
    