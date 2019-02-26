"""
NxN 크기의 미로에서 출발지 목적지가 주어진다.

이때 최소 몇 개의 칸을 지나면 출발지에서 도착지에 다다를 수 있는지 알아내는 프로그램을 작성하시오.

경로가 있는 경우 출발에서 도착까지 가는데 지나야 하는 최소한의 칸 수를, 경로가 없는 경우 0을 출력한다.

다음은 5x5 미로의 예이다. 1은 벽, 0은 통로를 나타내며 미로 밖으로 벗어나서는 안된다.

13101
10101
10101
10101
10021

마지막 줄의 2에서 출발해서 0인 통로를 따라 이동하면 맨 윗줄의 3에 5개의 칸을 지나 도착할 수 있다.


[입력]

첫 줄에 테스트 케이스 개수 T가 주어진다.  1<=T<=50

다음 줄부터 테스트 케이스의 별로 미로의 크기 N과 N개의 줄에 걸쳐 미로의 통로와 벽에 대한 정보가 주어진다. 5<=N<=100

0은 통로, 1은 벽, 2는 출발, 3은 도착이다.

[출력]

각 줄마다 "#T" (T는 테스트 케이스 번호)를 출력한 뒤, 답을 출력한다.
"""

t = int(input())

tc = 1

graph = [[0 for _ in range(101)] for _ in range(101)]
depth = [[0 for _ in range(101)] for _ in range(101)]
qx = [0 for _ in range(20000)]
qy = [0 for _ in range(20000)]
dx = [0, 1, 0, -1]
dy = [-1, 0, 1, 0]

def isInside(x, y, n) :
    if x >= n or x < 0 : return False
    if y >= n or y < 0 : return False
    
    return True
	
while tc <= t :
    n = int(input())
    ans = 0
    sx = -1
    sy = -1
	
    rear = -1
    front = -1
    for i in range(n) :
        string = input()
        for j in range(n) :
            depth[i][j] = 0
            graph[i][j] = string[j]
            if graph[i][j] == '2' :
            	sx = j; sy = i
    
    depth[sy][sx] = 1
    rear += 1
    qx[rear] = sx
    qy[rear] = sy
    
    while(rear != front) :
        front += 1
        cx = qx[front]
        cy = qy[front]

        if graph[cy][cx] == '3' :
            ans = depth[cy][cx] - depth[sy][sx] - 1
            break
            
        for d in range(4) :
            if depth[cy+dy[d]][cx+dx[d]] == 0 and isInside(cy+dy[d], cx+dx[d], n) and (graph[cy+dy[d]][cx+dx[d]] == '0' or graph[cy+dy[d]][cx+dx[d]] == '3')  :
                rear += 1
                qx[rear] = cx+dx[d]
                qy[rear] = cy+dy[d]
                depth[cy+dy[d]][cx+dx[d]] = depth[cy][cx] + 1
              
    print("#{} {}".format(tc, ans))
    tc += 1
