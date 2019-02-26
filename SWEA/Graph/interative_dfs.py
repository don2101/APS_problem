graph = [[0]*8 for i in range(8)]
visited = [False] * 8
stack = [0] * 100
top = -1


graph[2][1] = 1
graph[1][2] = 1
graph[2][1] = 1
graph[1][3] = 1
graph[3][1] = 1
graph[2][4] = 1
graph[4][2] = 1
graph[2][5] = 1
graph[5][2] = 1
graph[4][6] = 1
graph[6][4] = 1
graph[5][6] = 1
graph[6][5] = 1
graph[6][7] = 1
graph[7][6] = 1
graph[3][7] = 1
graph[7][3] = 1


v = 1

print(v, end=' ')
visited[v] = True

while True :
    for i in range(1, 8) :
        if not visited[i] and graph[v][i] == 1 :
            top += 1
            stack[top] = v
            w = i
            
            break
    
    while w != -1 :
        print(w, end=' ')
        visited[w] = True
        top += 1
        stack[top] = w
        v = w
        w = -1
        for i in range(1, 8) :
            if not visited[i] and graph[v][i] == 1 :
                top += 1
                stack[top] = v
                w = i
                
                break
    
    v = stack[top]
    top -= 1
    if top == -1 : break