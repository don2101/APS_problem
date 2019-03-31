# 1. 조합, 백 트래킹 문제
# 2. 현재 위치에서 연료로 도달 가능한 거리 dist를 설정
# 3. dist가 최종 도달해야 되는 n보다 작고 충전 횟수 cnt가 이미 ans보다 크면 탐색 종료(백 트래킹)
# 4. 그렇지 않을 경우 n보다 작은 거리에 대해 탐색 진행
# 5. n에 도달하면 ans를 cnt로 갱신


t = int(input())
tc = 1
ans = 99999


def dfs(fuels, current, n, cnt):
    global ans
    
    if current == n:
        if cnt < ans:
            ans = cnt
        return

    dist = fuels[current] + current

    if dist < n and cnt+1 >= ans:
        return

    for i in range(current+1, dist+1):    
        if i <= n:
            dfs(fuels, i, n, cnt+1)


while tc <= t:
    ans = 99999
    fuels = list(map(int, input().split()))
    n = fuels[0]

    dfs(fuels, 1, n, 0)

    print("#{} {}".format(tc, ans-1))
    tc += 1


