# 1. 배열의 모든 경로를 조사
# 2. 모든 경로를 오른쪽, 아래쪽 방향으로 조사
# 3. 조사하며 범위 내에 있을 경우 해당 값을 더하고 다음 방향으로 진행
#   3.1 만약 더한 값이 이미 있는 값 보다 크면 탐색을 하지 않음(가지치기)
# 4. 최종 지점에 도달했을 때 이미 있는 값과 비교하여 더 작은 값을 저장


t = int(input())
tc = 1

dx = [1, 0]
dy = [0, 1]
ans = 500

def isInside(y, x, n):
    if y >= n or y < 0: return False
    if x >= n or x < 0: return False
    
    return True
    
def dfs(g, cur_y, cur_x, n, result):
    global ans
    if cur_y == n-1 and cur_x == n-1:
        result += g[cur_y][cur_x]
        
        if ans > result:
            ans = result
        return
    
    result += g[cur_y][cur_x]
    if result > ans:
        return
    
    for d in range(2):
        if isInside(cur_y+dy[d], cur_x+dx[d], n):
            dfs(g, cur_y+dy[d], cur_x+dx[d], n, result)
    
    
while tc <= t:
    ans = 500
    n = int(input())
    graph = []
    
    for i in range(n):
        graph.append(list(map(int, input().split())))
    
    dfs(graph, 0, 0, n, 0)
    
    
    print("#{} {}".format(tc, ans))
    tc += 1
    