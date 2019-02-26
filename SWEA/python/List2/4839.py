tc = 1
t = int(input())

while tc <= t :
    page, Ap, Bp = tuple(map(int, input().split(' ')))
    ans = 0
    AGP = False
    BGP = False
    
    Ac = -1
    Bc = -1
    As = 1
    Bs = 1
    Ae = page
    Be = page
    
    while not AGP and not BGP :
        Ac = int((As+Ae)/2)
        Bc = int((Bs+Be)/2)
        if Ac == Ap :
            AGP = True
        elif Ac < Ap :
            As = Ac
        else :
            Ae = Ac
            
        if Bc == Bp :
            BGP = True
        elif Bc < Bp :
            Bs = Bc
        else :
            Be = Bc
            
    if AGP and not BGP : 
        ans = "A"
    elif BGP and not AGP : 
        ans = "B"
	
    print(f"#{tc} {ans}")
    
    tc += 1