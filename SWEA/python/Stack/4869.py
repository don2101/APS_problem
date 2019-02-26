tc = int(input())

def cal(n) :
    k = 1
    for i in range(2, n+1)  :
        if i&1 :
            k = k*2 - 1
        else : k = k*2 + 1
    
    return k
        
for t in range(1, tc+1) :
    ans = 0
    width = int(input())
    n = width // 10
    ans = cal(n)
    
    print("#{} {}".format(t, ans))