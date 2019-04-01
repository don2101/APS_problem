t = int(input())
tc = 1
ans = 9999999


def min_value(n1, n2):
    if n1 > n2: return n2
    return n1


while tc <= t:
    ans = 9999999
    
    n, e = (map(int, input().split()))
    graph = [[-1 for _ in range(n+1)] for _ in range(n+1)]
    dist = [9999999 for _ in range(n+1)]
    visited = [False for _ in range(n+1)]

    for i in range(e):
        v, w, d = (map(int, input().split()))
        graph[v][w] = d

    dist[0] = 0
    visited[0] = True
    s = 0
    
    while s != n:
        for i in range(n+1):
            if graph[s][i] != -1 and not visited[i]:
                dist[i] = min_value(dist[s]+graph[s][i], dist[i])
        
        min_idx = 0
        min_dist = 9999999
        for i in range(n+1):
            if not visited[i]:
                if dist[i] < min_dist:
                    min_idx = i
                    min_dist = dist[i]
        
        visited[min_idx] = True
        s = min_idx
    
    ans = dist[n]
    print("#{} {}".format(tc, ans))
    tc += 1
    
	