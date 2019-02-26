tc = int(input())
graph = [[0]*(52) for _ in range(52)]
visited = [False] * 52

def dfs(s, g, v) :
    if s == g : return 1
    
    visited[s] = True
    k = 0
    for i in range(1, v+1) :
        if graph[s][i] == 1 and not visited[i]  :
            k = dfs(i, g, v)
            if k == 1 :
                break
    
    return k
    

for t in range(1, tc+1) :
    ans = 0
    v, e = map(int, input().split())
    
    for i in range(0, v+1) :
        for j in range(0, v+1) :
            graph[i][j] = 0
	
    for i in range(0, v+1) :
    	visited[i] = False
    
    for _ in range(e) :
        n1, n2 = map(int, input().split())
        graph[n1][n2] = 1
    
    s, g = map(int, input().split())
    ans = dfs(s, g, v)
    
    print("#{} {}".format(t, ans))