"""
N X N크기의 농장이 있다.
이 농장에는 이상한 규칙이 있다.
규칙은 다음과 같다.
   ① 농장은 크기는 항상 홀수이다. (1 X 1, 3 X 3 … 49 X 49)
   ② 수확은 항상 농장의 크기에 딱 맞는 정사각형 마름모 형태로만 가능하다.
                                 
농장의 크기 N와 농작물의 가치가 주어질 때, 규칙에 따라 얻을 수 있는 수익은 얼마인지 구하여라.

[제약 사항]
농장의 크기 N은 1 이상 49 이하의 홀수이다. (1 ≤ N ≤ 49)
농작물의 가치는 0~5이다.

[입력]
가장 첫 줄에는 테스트 케이스의 개수 T가 주어지고, 그 아래로 각 테스트 케이스가 주어진다.
각 테스트 케이스에는 농장의 크기 N과 농장 내 농작물의 가치가 주어진다.

[출력]
각 줄은 '#t'로 시작하고, 공백으로 농장의 규칙에 따라 얻을 수 있는 수익을 출력한다.
(t는 테스트 케이스의 번호를 의미하며 1부터 시작한다.)
"""

"""
사용 로직
1. 2차월 배열을 조건에 따라 제어
"""


t = int(input())
tc = 1

map = [[0 for _ in range(49)] for _ in range(49)]

while tc <= t :
    ans = 0
    n = int(input())
    
    for i in range(n) :
        number = int(input())
        for j in range(n) :
            div = 1
            for _ in range(n-1-j) :
                div *= 10
            num = number // div
            number %= div
            map[i][j] = num
    
    start = n // 2
    end = n // 2 + 1
    step = -1

    for i in range(n) :
        for j in range(start, end) :
            ans += map[i][j]
        if i >= n//2 : step = 1
        
        start += step
        end -= step

    print("#{} {}".format(tc, ans))
    tc += 1
    