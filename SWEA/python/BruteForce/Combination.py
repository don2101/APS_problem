n = 5
r = 3
array = [i for i in range(n)]
temp = [0 for i in range(n)]
count = 0


# start를 뽑고, start 부터 n-r+k까지 다시 combination.
def combination(array, temp, k, start):
    global r
    global n
    global count
    
    if k == r:
        print(temp[:r])
        count += 1
        return

    for i in range(start, n-r+k+1):
        temp[k] = array[i]
        combination(array, temp, k+1, i+1)

combination(array, temp, 0, 0)
print(count)


dp = [[-1 for i in range(n+1)] for i in range(n+1)]

def combination_memo(dp, k, p):
    if(p <= 0):
        return 1
    elif k < p : return 0
    elif k <= 1: return 1
    
    if dp[k][p] == -1:
        dp[k][p] = combination_memo(dp, k-1, p-1) + combination_memo(dp, k-1, p)
        return dp[k][p]
    else:
        return dp[k][p]

print(combination_memo(dp, n, r))


# array = [i for i in range(n)]

# def combination_dp(array, dp):
#     dp[0][0] = 0
#     dp[0][1] = 0
#     dp[1][0] = 0
#     dp[1][1] = 1

#     for i in range(2, n):
#         for j in range(2, r):
#             dp[i][j] = dp[i-1][j-1] + dp[i-1][j]
    
#     print(dp[n-1][r-1])

# combination_dp(array, dp)