tc = int(input())
test = 1

while test <= tc :
    p = input()
    t = input()
    
    for i in range(0, len(t)-len(p)+1) :
        matching = True
        for j in range(0, len(p)) :
            if t[i+j] != p[j] :
                matching = False
                break
        if matching == True :
            break
    
    ans = 0
    if matching : ans = 1
    
    print(f"#{test} {ans}")
    
    test += 1
    