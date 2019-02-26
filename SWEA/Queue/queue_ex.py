q = [0] * 3

front = -1
rear = -1

front += 1
q[front] = 1
front += 1
q[front] = 2
front += 1
q[front] = 3

rear += 1
print(f"{q[rear]}")
rear += 1
print(f"{q[rear]}")
rear += 1
print(f"{q[rear]}")
