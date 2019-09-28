# 스티커 하나를 선택하면 양쪽 스티커를 선택할 수 없도록 하고, 선택한 스티커의 최종합이 가장 크도록 하는 문제
# dp로 해결

def max_num(i, j):
    if i > j:
        return i
    else: return j

    
def solution(sticker):
    answer = 0
    length = len(sticker)
    dp = [[0 for _ in range(2)] for _ in range(length) ]

    dp[0][1] = sticker[0]
    dp[1][1] = sticker[1]
    dp[1][0] = sticker[0]

    for i in range(2, length):
        dp[i][1] = dp[i-1][0] + sticker[i]
        dp[i][0] = max_num(dp[i-1][0], dp[i-1][1])
    
    answer = max_num(dp[length-1][1], dp[length-1][0])
    
    return answer