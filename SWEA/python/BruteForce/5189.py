# 1. 모든 가능한 경로를 조사
# 2. 경로를 조사하며 방문하지 않은 곳이 있다면, distance를 증가시키고 이동
#   2-1. distance가 기존의 answer보다 크다면 진행하지 않음
#   2-2. 0에서 무조건 시작해야 되기 때문에 main에서 한번은 dfs를 진행
# 3. 모든 노드가 visited라면 0번 노드로 이동
# 4. 0번 노드에 도달하면 answer과 distance를 비교해서 적은 것을 저장


t = int(input())
tc = 1

ans = 99999

def dfs(graph, visited, cur_node, distance):
    global ans
    
    if cur_node == 0:
        if ans > distance:
            ans = distance
        return
    
    count = 0
    for i in range(1, n):
        if not visited[i]:
            distance += graph[cur_node][i]
            
            if distance > ans: 
                distance -= graph[cur_node][i]
                continue
            
            visited[i] = True
            dfs(graph, visited, i, distance)
            visited[i] = False
            distance -= graph[cur_node][i]
        else: count += 1
    
    if count == n-1:
        distance += graph[cur_node][0]
        dfs(graph, visited, 0, distance)
        distance -= graph[cur_node][0]


while tc <= t:
    ans = 99999
    n = int(input())
    graph = []
    visited = [False for _ in range(n)]
    
    for i in range(n):
        graph.append(list(map(int, input().split())))
        
    start_node = 0
    cur_node = 0
    distance = 0
    
    for i in range(1, n):
        distance += graph[cur_node][i]
        visited[i] = True
        dfs(graph, visited, i, distance)
        visited[i] = False
        distance -= graph[cur_node][i]
    
    print("#{} {}".format(tc, ans))
    tc += 1