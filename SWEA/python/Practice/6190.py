"""
정곤이는 자신이 엄청난 수학자임을 증명하기 위해, 어떤 규칙 만족하는 수를 찾아보기로 했다.
그 규칙은 단조 증가하는 수인데, 각 숫자의 자릿수가 단순하게 증가하는 수를 말한다.
어떤 k자리 수 X = d1d2…dk 가 d1 ≤ d2 ≤ … ≤ dk 를 만족하면 단조 증가하는 수이다.
예를 들어 111566, 233359는 단조 증가하는 수이고, 12343, 999888은 단조 증가하는 수가 아니다.
양의 정수 N 개 A1, …, AN이 주어진다.
1 ≤ i < j ≤ N 인 두 i, j에 대해, Ai x Aj값이 단조 증가하는 수인 것들을 구하고 그 중의 최댓값을 출력하는 프로그램을 작성하라.

[입력]
첫 번째 줄에 테스트 케이스의 수 T가 주어진다.
각 테스트 케이스의 첫 번째 줄에는 하나의 정수 N(1 ≤N ≤ 1,000) 이 주어진다.
두 번째 줄에는 N개의 정수 A1, …, AN(1 ≤ Ai ≤ 30,000) 이 공백 하나로 구분되어 주어진다.

[출력]
각 테스트 케이스마다 단조 증가하는 수인 Ai x Aj중에서 그 최댓값을 출력한다.
만약 Ai x Aj중에서 단조 증가하는 수가 없다면 -1을 출력한다.
"""

"""
사용 로직
1. 모든 경우의 수에 대해 곱을 구하고
2. 각 수를 10으로 나눠 가며 조건을 확인
"""

t = int(input())
tc = 1

def increment(num) :
    while num > 1 :
        num1 = num % 10
        num = num // 10
        num2 = num % 10
        if num1 < num2 : return False
        
    return True
    

while tc <= t :
    ans = -1
    n = int(input())
    
    numbers = list(map(int, input().split()))
    
    for i in range(0, n-1) :
        for j in range(i+1, n) :
            num = numbers[i] * numbers[j]
            if increment(num) :
                if ans < num :
                    ans = num
    
    print("#{} {}".format(tc, ans))
    tc += 1