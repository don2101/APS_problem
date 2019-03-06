"""
다솔이는 어떤 문자열을 하나 가지고 있는데, 이 문자열이 별로 아름답지 못하다고 생각하고 있다.
그래서 장식을 해주기로 했다.
예를 들어 문자열이 “D”라면 주위를 ‘#’로 이루어진 다이아몬드로 감싸서 다음과 같이 5x5크기로 장식한다.
빈 곳은 ‘.’로 표시한다.

만약 문자열의 길이가 1보다 더 크면, 인접한 문자는 ‘#’과 ‘.’을 공유하여 장식한다.
주어진 문자열을 장식해주는 프로그램을 작성하라.

[입력]
첫 번째 줄에 테스트 케이스의 수 T가 주어진다.
각 테스트 케이스의 첫 번째 줄에는 길이가 1이상 50이하인 문자열이 주어진다.

[출력]
각 테스트 케이스마다 다섯 줄에 걸쳐 장식된 문자열을 출력한다
"""

"""
사용 로직
1. 문자열 길이에 따라 조건에 맞게 출력
"""

t = int(input())
tc = 1

while tc <= t :
    string = input()
    length = len(string)
    
    for i in range(length) :
        print("..#.", end="")
    print(".")
    
    for i in range(2*length) :
        print(".#", end="")
    print(".")
    
    for i in range(length) :
        print("#.{}.".format(string[i]), end="")
    print("#")

    for i in range(2*length) :
        print(".#", end="")
    print(".")
    
    for i in range(length) :
        print("..#.", end="")
    print(".")
    

    
    tc += 1