# 1. 모든 가중치가 같고, 모든 노드를 방문할 필요가 없으므로 bfs 문제
# 2. q와 dq에 다음에 도달할 수, 다음에 도달할 깊이를 저장한다
# 3. 각 노드에 도착해서 조건 검사 후 다으멩 도달해야 할 노드를 q에 저장
# 4. 도달해야되는 수 m에 도달하면 탐색 종료


t = int(input())
tc = 1
visited = [False for _ in range(1000001)]
q = [0 for _ in range(1000001)]
dq = [0 for _ in range(1000001)]


while tc <= t:
    ans = 9999999
    n, m = (map(int, input().split()))
    visited = [False for _ in range(1000001)]
    
    qf = 0
    qr = 0

    q[qr] = n
    dq[qr] = 0
    qr += 1

    while qf != qr:
        cur = q[qf]
        depth = dq[qf]
        qf = (qf+1)%1000000
        if cur == m:
            if depth < ans:
                ans = depth
                break

        if cur < 1 or cur > 1000000 or depth > ans:
            continue

        if not visited[cur]:
            visited[cur] = True
            if cur < m:
                if cur*2 >= 1 and cur*2 <= 1000000 and depth+1 < ans:
                    dq[qr] = depth+1
                    q[qr] = cur*2
                    qr = (qr+1)%1000000
                if cur+1 >= 1 and cur+1 <= 1000000 and depth+1 < ans:
                    dq[qr] = depth+1
                    q[qr] = cur+1
                    qr = (qr+1)%1000000

            if cur-1 >= 1 and cur-1 <= 1000000 and depth+1 < ans:
                dq[qr] = depth+1
                q[qr] = cur-1
                qr = (qr+1)%1000000
            if cur-10 >= 1 and cur-10 <= 1000000 and depth+1 < ans:
                dq[qr] = depth+1
                q[qr] = cur-10
                qr = (qr+1)%1000000

    print("#{} {}".format(tc, ans))
    tc += 1
    