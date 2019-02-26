candy = 20
person = [1 for i in range(101)]

ans = 0

q = [0 for i in range(100)]

rear = -1
front = -1

while candy > 0 :
    p = 1
    
    rear += 1
    q[rear] = p
    candy -= person[p]

    

    
print(ans)