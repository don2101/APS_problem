# 1. MST 문제. Prim 알고리즘 사용
# 2. 방문한 노드를 visited에 저장하고, 방문되지 않는 노드로 연결된 간선중 가장 길이가 짧은 간선을 선택
# 3. 방문한 노드의 수가 최대 노드수 이하일 동안 반복

t = int(input())
tc = 1


while tc <= t:
    ans = 0
    v, e = (map(int, input().split()))   
    graph = [[0 for _ in range(v+1)] for _ in range(v+1)]
    visited = [-1 for _ in range(v+1)]
    checked = [False for _ in range(v+1)]
    vp = 0

    for i in range(e):
        n1, n2, w = (map(int, input().split()))
        graph[n1][n2] = w
        graph[n2][n1] = w
    
    cur = 0
    
    while vp < v:
        visited[vp] = cur
        checked[cur] = True
        vp += 1

        min_dist = 99999
        min_idx = -1
        
        for p in range(vp):
            s = visited[p]

            for w in range(v+1):
                if not checked[w]:
                    if graph[s][w] > 0 and graph[s][w] < min_dist:
                        min_dist = graph[s][w]
                        min_idx = w
        
        ans += min_dist
        cur = min_idx

    print("#{} {}".format(tc, ans))
    tc += 1
    
    