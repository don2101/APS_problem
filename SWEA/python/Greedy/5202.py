# 1. 끝나는 시간을 기준으로 시간 배분
# 2. 끝나는 시간이 가장 빠른 시간을 선택
#   2.1. 동시에 끝나는 것은 상관이 없음
# 3. 해당 시간을 visited처리하고, 그 시간보다 이전에 시작하는 모든 시간을 visited처리
# 4. 더이상 선택되는 시간이 없으면 종료

t = int(input())
tc = 1

while tc <= t:
    ans = 0
    n = int(input())
    start = [0 for _ in range(n)]
    end = [0 for _ in range(n)]
    visited = [False for _ in range(n)]
    
    for i in range(n):
        s, e = (map(int, input().split()))
        start[i] = s
        end[i] = e
    
    while True:
        find = False
        min_time = 25
        min_idx = -1
        
        for i in range(n):
            if not visited[i] and end[i] < min_time :
                min_time = end[i]
                min_idx = i
                find = True
        
        if not find: break
        visited[min_idx] = True
        ans += 1

        for i in range(n):
            if not visited[i] and start[i] < min_time:
                visited[i] = True

    
    print("#{} {}".format(tc, ans))
    tc += 1
    