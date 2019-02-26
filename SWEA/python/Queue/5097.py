"""
N개의 숫자로 이루어진 수열이 주어진다. 맨 앞의 숫자를 맨 뒤로 보내는 작업을 M번 했을 때, 수열의 맨 앞에 있는 숫자를 출력하는 프로그램을 만드시오.

[입력]

첫 줄에 테스트 케이스 개수 T가 주어진다.  1<=T<=50

다음 줄부터 테스트 케이스의 첫 줄에 N과 M이 주어지고, 다음 줄에 10억 이하의 자연수 N개가 주어진다. 3<=N<=20, N<=M<=1000,

[출력]

각 줄마다 "#T" (T는 테스트 케이스 번호)를 출력한 뒤, 번호를 출력한다.

"""


t = int(input())

tc = 1
queue = [0 for _ in range(0, 200)]

while tc <= t :
    ans = 0

    n, m = (map(int, input().split()))
    
    temp = list(map(int, input().split()))
    rear = len(temp)-1
    front = -1
    
    for i in range(0, len(temp)) :
        queue[i] = temp[i]
        
    for i in range(0, m) :
        front = (front+1) % n
        num = queue[front]
        rear = (rear + 1) % n
        queue[rear] = num
    
    front = (front + 1) % n
    ans = queue[front]
    print("#{} {}".format(tc, ans))
    tc += 1
    
    