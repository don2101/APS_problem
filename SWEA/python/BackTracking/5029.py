# 1. 순열, 백 트래킹 문제
# 2. 각 행에서 사용하지 않은 열이고, cost가 ans보다 작다면 탐색 진행
# 3. 최종 depth n에 도달하면 ans를 cost로 갱신


t = int(input())
tc = 1
ans = 9999999

def dfs(graph, vistited, depth, n, cost):
    global ans

    if depth == n:
        if ans > cost:
            ans = cost
        return

    for i in range(n):
        if not visited[i]:
            value = graph[depth][i]
            
            if(cost+value < ans):
                visited[i] = True
                dfs(graph, visited, depth+1, n, cost+value)
                visited[i] = False


while tc <= t:
    ans = 9999999
    n = int(input())
    graph = [list(map(int, input().split())) for _ in range(n)]
    visited = [False for _ in range(n)]

    dfs(graph, visited, 0, n, 0)

    print("#{} {}".format(tc, ans))
    tc += 1

