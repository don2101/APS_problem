"""
N X N 크기의 단어 퍼즐을 만들려고 한다. 입력으로 단어 퍼즐의 모양이 주어진다.
주어진 퍼즐 모양에서 특정 길이 K를 갖는 단어가 들어갈 수 있는 자리의 수를 출력하는 프로그램을 작성하라.
딱 k에 맞게 들어가는 칸을 찾아야 한다.

[제약 사항]
1. N은 5 이상 15 이하의 정수이다. (5 ≤ N ≤ 15)
2. K는 2 이상 N 이하의 정수이다. (2 ≤ K ≤ N)

[입력]
입력은 첫 줄에 총 테스트 케이스의 개수 T가 온다.
다음 줄부터 각 테스트 케이스가 주어진다.
테스트 케이스의 첫 번째 줄에는 단어 퍼즐의 가로, 세로 길이 N 과, 단어의 길이 K 가 주어진다.
테스트 케이스의 두 번째 줄부터 퍼즐의 모양이 2차원 정보로 주어진다.
퍼즐의 각 셀 중, 흰색 부분은 1, 검은색 부분은 0 으로 주어진다.

[출력]
테스트 케이스 t에 대한 결과는 “#t”을 찍고, 한 칸 띄고, 정답을 출력한다.
(t는 테스트 케이스의 번호를 의미하며 1부터 시작한다.)
"""

"""
사용 로직
1. 2차원 배열 제어
2. 방향 제어
"""

t = int(input())
tc = 1

graph = [[0 for _ in range(15)] for _ in range(15)]

def isInside(y, x, n) :
    if x >= n or x < 0 : return False
    if y >= n or y < 0 : return False
    return True

def possible(g, y, x, k, n, d) :
    xd = [1, 0]
    yd = [0, 1]
    
    if isInside(y-yd[d], x-xd[d], n) and g[y-yd[d]][x-xd[d]] == 1 : return False
    
    for i in range(k) :
        if not isInside(y+yd[d]*i, x+xd[d]*i, n) : return False
        if g[y+yd[d]*i][x+xd[d]*i] == 0 : return False
    
    if isInside(y+yd[d]*k, x+xd[d]*k, n) and g[y+yd[d]*k][x+xd[d]*k] == 1 : return False
    
    return True
    

while tc <= t :
    ans = 0

    n, k = (map(int, input().split()))
    
    for i in range(n) :
        string = list(map(int, input().split()))
        for j in range(n) :
            graph[i][j] = string[j]
    
    for i in range(n) :
        for j in range(n) :
            if graph[i][j] :
                if possible(graph, i ,j, k, n, 0) : ans += 1
                if possible(graph, i ,j, k, n, 1) : ans += 1
                

    print("#{} {}".format(tc, ans))
    tc += 1