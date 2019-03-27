# 1. 순열, 백 트래킹 문제.
# 2. 최초에 각 노드간 거리를 n*n 배열에 미리 계산해 놓는다.
# 3. work에서 시작하며, 모든 노드 중 하나를 선택해 이동하며 distance를 증가
# 4. 방문하지 않은 노드 중 하나를 선택해가며 distance증가
#   4.1. distance가 이미 있는 결과보다 크다면 더 이상 탐색을 하지 않음
# 5. 마지막 level에 도달하면 home까지의 거리를 구하고, 기존 값 보다 적을경우 저장


t = int(input())
tc = 1

ans = 99999999


def absolute(num):
    if num < 0: return -num
    return num


def dfs(graph, visited, visit, home, node, level, distance, n):
    global ans
    
    if level == n-1:
        distance += abs(visit[node][0]-home[0]) + abs(visit[node][1]-home[1])
        if distance < ans:
            ans = distance
        
        return
    
    for i in range(n):
        if not visited[i]:
            distance += abs(visit[node][0]-visit[i][0]) + abs(visit[node][1]-visit[i][1])
            if distance > ans:
                distance -= abs(visit[node][0]-visit[i][0]) + abs(visit[node][1]-visit[i][1])
                continue

            visited[i] = True
            dfs(graph, visited, visit, home, i, level+1, distance, n)
            visited[i] = False
            distance -= abs(visit[node][0]-visit[i][0]) + abs(visit[node][1]-visit[i][1])


while tc <= t:
    ans = 99999999
    n = int(input())
    input_list = list(map(int, input().split()))
    
    work = [input_list[0], input_list[1]]
    home = [input_list[2], input_list[3]]
    visit = []
    visited = [False for _ in range(n)]
    l = len(input_list)
    
    for i in range(4, l, 2):
        visit.append([input_list[i], input_list[i+1]])
    
    graph = [[0 for _ in range(n)] for _ in range(n)]
    
    for i in range(n):
        for j in range(n):
            graph[i][j] = abs(visit[i][0]-visit[j][0]) + abs(visit[i][1]-visit[j][1])
    
    distance = 0
    
    for i in range(n):
        distance += abs(work[0]-visit[i][0]) + abs(work[1]-visit[i][1])
        visited[i] = True
        dfs(graph, visited, visit, home, i, 0, distance, n)
        visited[i] = False
        distance -= abs(work[0]-visit[i][0]) + abs(work[1]-visit[i][1])

    print("#{} {}".format(tc, ans))
    tc += 1