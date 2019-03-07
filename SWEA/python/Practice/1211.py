"""
아래 <그림 2>와 같은 100 x 100 크기의 2차원 배열로 주어진 사다리에 대해서, 
모든 출발점을 검사하여 가장 짧은 이동 거리를 갖는 시작점 x(복수 개인 경우 가장 큰 x좌표)를 반환하는 코드를 작성하라.

[제약사항]
한 막대에서 출발한 가로선이 다른 막대를 가로질러서 연속하여 이어지는 경우는 없다.

[입력]
각 테스트 케이스의 첫 번째 줄에는 테스트 케이스의 번호가 주어지며, 바로 다음 줄에 테스트 케이스가 주어진다.
총 10개의 테스트 케이스가 주어진다.

[출력]
#부호와 함께 테스트 케이스의 번호를 출력하고, 공백 문자 후 도착하게 되는 출발점의 x좌표를 출력한다.
"""

"""
사용 로직
1. 2차원 배열 제어
2. 방향 제어
"""

t = 10
tc = 1

graph = [[0 for _ in range(100)] for _ in range(100)]

def isInside(y, x) :
    if y >= 100 or y < 0 : return False
    if x >= 100 or x < 0 : return False
    
    return True

while tc <= t :
    testCase = int(input())
    ans = 0
    
    positionX = [0 for _ in range(100)]
    pointer = 0
    
    for i in range(100) :
        string = list(map(int, input().split()))
        for j in range(100) :
            graph[i][j] = string[j]
    
    for i in range(100) :
        if graph[0][i] : 
            positionX[pointer] = i
            pointer += 1
    
    maxDistance = 0
    for k in range(pointer) :
        start = positionX[k]
        curX = start
        curY = 0
        distance = 1
        
        while curY < 99 :
            if curX < 99 and graph[curY][curX+1] == 1 : 
                while curX < 99 and graph[curY][curX+1] == 1 :
                    distance += 1
                    curX += 1
            elif curX > 0 and graph[curY][curX-1] == 1 :
                while curX > 0 and graph[curY][curX-1] == 1 :
                    distance += 1
                    curX -= 1
            curY += 1
            distance += 1

        if maxDistance <= distance : 
            ans = start
            maxDistance = distance
    
    print("#{} {}".format(tc, ans))
    tc += 1