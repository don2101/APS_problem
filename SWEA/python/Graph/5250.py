# 1. 모든 노드를 조사할 필요가 없고, 노드마다 가중치가 존재하므로 다익스트라 알고리즘 문제
# 2. 각 노드에서 4방향으로 dist 갱신
# 3. 최소 dist를 가진 노드로 이동하여 반복
#   3.1. 최소 dist를 가진 노드를 빠르게 구하기 위해, 방문 가능한 모든 노드를 중복없이 배열에 저장


t = int(input())
tc = 1

dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]


def min_value(n1, n2):
    if n1 > n2: return n2
    return n1


def is_inside(x, y, n):
    if x < 0 or x >= n: return False
    if y < 0 or y >= n: return False
    
    return True


def dist_cal(d1, d2):
    if d1-d2 <= 0: return 0
    return d1-d2


while tc <= t:
    ans = 0
    n = int(input())
    graph = [0 for _ in range(n)]
    visited = [[False for _ in range(n)] for _ in range(n)]
    dist = [[9999999 for _ in range(n)] for _ in range(n)]
    sx = [-1 for _ in range(11000)]
    sy = [-1 for _ in range(11000)]
    sp = 1

    for i in range(n):
        graph[i] = list(map(int, input().split()))

    dist[0][0] = 0
    cur_x = 0
    cur_y = 0
    
    while cur_x != n-1 or cur_y != n-1:
        visited[cur_y][cur_x] = True

        for d in range(4):
            if is_inside(cur_x+dx[d], cur_y+dy[d], n) and not visited[cur_y+dy[d]][cur_x+dx[d]]:
                dist[cur_y+dy[d]][cur_x+dx[d]] = min_value(dist[cur_y+dy[d]][cur_x+dx[d]], dist[cur_y][cur_x]+dist_cal(graph[cur_y+dy[d]][cur_x+dx[d]], graph[cur_y][cur_x])+1)
                
                find = False
                for p in range(sp):
                    if sx[p] == cur_x+dx[d] and sy[p] == cur_y+dy[d]:
                        find = True
                        break
                if not find:
                    sx[sp] = cur_x+dx[d]
                    sy[sp] = cur_y+dy[d]
                    sp += 1

        min_dist = 9999999
        min_p = 0

        for p in range(sp):
            tx = sx[p]
            ty = sy[p]
            
            if not visited[ty][tx] and min_dist > dist[ty][tx]:
                min_dist = dist[ty][tx]
                min_p = p

        cur_x = sx[min_p]
        cur_y = sy[min_p]

        for p in range(min_p, sp-1):
            sx[p] = sx[p+1]
            sy[p] = sy[p+1]
        sp -= 1
 
    ans = dist[n-1][n-1]
    print("#{} {}".format(tc, ans))
    tc += 1
