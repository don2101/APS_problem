"""
여러 개의 수열을 정해진 규칙에 따라 합치려고 한다. 

수열 2의 첫 숫자 보다 큰 수자를 수열 1에서 찾아 그 앞에 수열 2를 끼워 넣는다.
합쳐진 수열에 대해, 수열 3의 첫 숫자보다 큰 숫자를 찾아 그 앞에 수열 3을 끼워 넣는다. 큰 숫자가 없는 경우 맨 뒤에 붙인다.
마지막 수열까지 합치고 나면, 맨 뒤의 숫자부터 역순으로 10개를 출력한다.

[입력]
첫 줄에 테스트케이스의 수 T가 주어진다. 1<=T<=50
다음 줄부터 테스트 케이스의 별로 첫 줄에 수열의 길이 N, 수열의 개수 M, 이후 M개의 줄에 걸쳐 1000이하의 자연수로 구성된 수열이 주어진다. 4<=N<=1000, 1<=M<=1000

[출력]
각 줄마다 "#T" (T는 테스트 케이스 번호)를 출력한 뒤, 완성된 수열의 맨 뒤부터 10개의 숫자를 역순으로 출력한다.
"""

"""
배운것
1. python에서 클래스 전역으로 변수를 설정할 시 새로 생성자로 생성해도 값을 그대로 유지가 된다.
    1.1 flush가 안된다는 의미
"""

class Dnode :
    data = 99999
    front = None
    prev = None
    
class DoublyList :

    def __init__(self) :
        self.head = Dnode()
        self.tail = Dnode()
        self.head.front = self.tail
        self.tail.prev = self.head
    
    def put(self, data, position) :
        newNode = Dnode()
        newNode.data = data
        newNode.front = position
        newNode.prev = position.prev
        position.prev.front = newNode
        position.prev = newNode
    
    def putList(self, tempList, n) :
        searchNode = self.head
        
        if searchNode.front.data > tempList[0] :
            for i in range(n) :
                self.put(tempList[i], searchNode.front)
                searchNode = searchNode.front
        else :
            while searchNode.front.data <= tempList[0] and searchNode.front != self.tail:
                searchNode = searchNode.front

            for i in range(n) :
                self.put(tempList[i], searchNode.front)
                searchNode = searchNode.front
    
    def printList(self) :
        searchNode = self.tail.prev
        for _ in range(10) :
            if searchNode == self.head : break
            print("{}".format(searchNode.data), end=" ")
            searchNode = searchNode.prev

t = int(input())
tc = 1

while tc <= t :
    n, m = (map(int, input().split()))
    
    dList = DoublyList()
    firstList = list(map(int, input().split()))
    
    for i in range(n) :
        dList.put(firstList[i], dList.tail)
    
    for i in range(m-1) :
        otherList = list(map(int, input().split()))
        dList.putList(otherList, n)

    print("#{}".format(tc), end=" ")
    dList.printList()
    print()
    dList
    tc += 1