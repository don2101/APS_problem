# 1. 순열, 백 트래킹 문제.
# 2. 모든 work를 살펴보며 확률을 곱해 나간다.
# 3. 이미 존재하는 결과보다 조건을 더 충족하지 못하면, 더 이상 탐색하지 않는다.


t = int(input())
tc = 1
ans = 0.0


def dfs(work, visited, level, result, n):
    global ans
    
    if level == n:
        if ans <= result:
            ans = result
        
        return
    
    for i in range(n):
        if not visited[i]:
            value = work[level][i]/100
            if value == 0.0:
                continue
            
            result *= value
            if result < ans:
                result /= value
                continue
            
            visited[i] = True
            dfs(work, visited, level+1, result, n)
            result /= value
            visited[i] = False
            
            
while tc <= t:
    ans = 0.0
    n = int(input())
    work = []
    visited = [False for _ in range(n)]
    
    for i in range(n):
        work.append(list(map(int, input().split())))
    
    dfs(work, visited, 0, 1.0, n)

    print("#{} {}".format(tc, ans))
    tc += 1