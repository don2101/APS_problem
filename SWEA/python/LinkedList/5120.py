"""
A사는 창립기념일 이벤트로 비밀번호 맞추기 대회를 열어, 최대 10개인 비밀번호를 맞추는 사람에게 기념품을 제공하기로 했다.
기념품을 받을 수 있도록 다음 조건에 맞는 비밀번호 찾기 프로그램을 작성하시오.
 
- 1000이하의 숫자 N개가 주어진다. 이때 시작 숫자가 정해지고, 첫 번째 지정 위치가 된다.
- 지정 위치부터 M번째 칸을 추가한다. 여기에 앞칸의 숫자와 뒤로 밀려난 칸의 숫자를 더해 넣는다. 추가된 칸이 새로운 지정 위치가 된다. 밀려난 칸이 없으면 시작 숫자와 더한다.
- 이 작업을 K회 반복하는데, M칸 전에 마지막 숫자에 이르면 남은 칸수는 시작 숫자부터 이어간다.
- 마지막 숫자부터 역순으로 숫자를 출력하면 비밀번호가 된다. 숫자가 10개 이상인 경우 10개까지만 출력한다.

다음은 N, M, K가 6, 3, 3이고, 주어진 숫자가 6, 2, 4, 9, 1, 5인 경우의 예이다. 6이 시작 숫자이자 첫번째 지정 위치가 된다.
(1) 3번째에 새로운 칸을 추가하고, 앞의 숫자 4와 뒤로 밀려난 9를 더해 칸을 채운다.
(2) 다시 3칸 뒤에 새로운 칸을 추가하고, 앞 뒤 숫자를 더해 넣는다.
(3) 다시 3칸 뒤에 칸을 추가하고 앞 뒤 숫자를 더해 넣는다.
암호는 역순인 5 6 1 9 13 4 2 8 6이 된다.

[입력]
첫 줄에 테스트케이스의 수 T가 주어진다. 1<=T<=50
다음 줄부터 테스트 케이스의 별로 첫 줄에 N, M, K가, 다음 줄에 1000이하의 자연수 N개가 주어진다. 3<=N, M, K<=1000

[출력]
각 줄마다 "#T" (T는 테스트 케이스 번호)를 출력한 뒤, 답을 출력한다.
"""

class Node :
    data = 99999
    front = None
    prev = None
    
class DList :

    def __init__(self) :
        self.head = Node()
        self.tail = Node()
        self.head.front = self.tail
        self.tail.prev = self.head
        self.tail.front = self.head
        self.head.prev = self.tail
    
    def put(self, data, position) :
        newNode = Node()
        newNode.data = data
        newNode.prev = position.prev
        newNode.front = position
        position.prev.front = newNode
        position.prev = newNode
        
    def step(self, m, k) :
        startNode = self.head.front
        
        while k > 0 :
            for _ in range(m-1) :
                startNode = startNode.front
                if startNode == self.head or startNode == self.tail : 
                    startNode = self.head.front

            data1 = startNode.data
            data2 = startNode.front.data
            if startNode.front == self.tail :
                data2 = self.head.front.data
            self.put(data1 + data2, startNode.front)
            startNode = startNode.front
            k -= 1
    
    def printList(self) :
        searchNode = self.tail.prev
        for _ in range(10) :
            if searchNode == self.head : break
            print("{}".format(searchNode.data), end=" ")
            searchNode = searchNode.prev
        print()
    
t = int(input())
tc = 1
        
while tc <= t :
    n, m, k = (map(int, input().split()))
    sList = list(map(int, input().split()))
    
    dlist = DList()

    for i in range(n) :
        dlist.put(sList[i], dlist.tail)
    
    dlist.step(m, k)    

    print("#{}".format(tc), end=" ")
    dlist.printList()
    tc += 1