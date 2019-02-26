def bfs(G, v) :
    n = len(G[0])
    visited = [False] * n

    queue = []

    queue.append(v)

    while(queue) :
        node = queue.pop(0)
        if(visited[node]) : continue
        
        visited[node] = True
        print(node, end=" ")
        
        for i in range(n) :
            if not visited[i] and G[node][i] == 1 :
                queue.append(i)

G = [[0 for _ in range(8)] for _ in range(8)]

G[1][2] = 1
G[1][3] = 1
G[2][4] = 1
G[2][5] = 1
G[4][6] = 1
G[5][6] = 1
G[3][7] = 1
G[6][7] = 1


bfs(G, 1)