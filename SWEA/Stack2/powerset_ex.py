numList = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
visited = [False] * 11
cnt = 0

def process_solve(r) :
    for i in range(len(r)) :
        print(r[i], end=" ")
    print()

# 후보 생성. 방문하지 않은 숫자 중 합이 n 이하가 되는 숫자를 후보에 추가
def makeCandidate(c, k, s, n) :
    for i in range(k, len(numList)) :
        if not visited[numList[i]] and s+numList[i] <= n:
            c.append(numList[i])

    return c

# k: 노드의 숫자, s: 현재까지 총합, n: 목표로하는 숫자
def backTracking(numlist, result, k, s, n) :
    if(k != 0) :
        s += k
        result.append(k)
        visited[k] = True
    
    # 다음으로 만들 후보
    candidate = []

    global cnt
    cnt += 1

    if(s == n) :
        process_solve(result)
    
    candidate = makeCandidate(candidate, k, s, n)
    
    for i in range(len(candidate)) :    
        backTracking(numList, result, candidate[i], s, n)
    
    # 노드를 빠져 나옴
    if(k != 0) :
        visited[k] = False
        s -= k
        result.pop()

backTracking(numList, [], 0, 0, 10)
print(cnt)