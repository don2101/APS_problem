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
    
    