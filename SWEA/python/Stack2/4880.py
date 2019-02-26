t = int(input())

tc = 1

def rcp(cards, s, e) :
    if s == e : return s
    win1 = rcp(cards, s, (s+e)//2)
    win2 = rcp(cards, ((s+e)//2)+1, e)
    if (cards[win1]%3) + 1 == cards[win2] : return win2
    elif cards[win1]-1 == cards[win2]%3 : return win1
    else : return win1

while tc <= t :
    ans = 0
    n = int(input())
    cards = list(map(int, input().split()))
    ans = rcp(cards, 0, n-1)
    
    print("#{} {}".format(tc, ans+1))
    tc += 1