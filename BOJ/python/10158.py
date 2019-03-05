dx = [ 1, 1, -1, -1 ]
dy = [ 1, -1, -1, 1 ]

def isInside(y, x, h, w) :
    if y > h or y < 0 : return False
    if x > w or x < 0 : return False

    return True

w, h = (map(int, input().split()))
p, q = (map(int, input().split()))
t = int(input())

d = 0

while t > 0 :
    while isInside(q+dy[d], p+dx[d], h, w) :
        p = p+dx[d]
        q = q+dy[d]
        t -= 1
        if(t <= 0): break
    
    if isInside(q+dy[(d+1)%4], p+dx[(d+1)%4], h, w) : d = (d+1)%4
    elif isInside(q+dy[(d+3)%4], p+dx[(d+3)%4], h, w) : d = (d+3)%4
    else : d = (d+2)%4


print("{} {}".format(p, q))

## 다른 방법
