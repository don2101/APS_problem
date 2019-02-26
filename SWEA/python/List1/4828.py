"""
N개의 정수 중에서 최대값 최소값의 차이를 구한다.
"""

T = int(input())

for test_case in range(1, T + 1):
    n = int(input())
    numbers = list(map(int, input().split()))
    
    maxNum = max(numbers)
    minNum = min(numbers)
    
    print("#{} {}".format(test_case, maxNum - minNum))