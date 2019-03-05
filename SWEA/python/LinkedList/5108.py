"""
N개의 10억 이하 자연수로 이뤄진 수열이 주어진다.
이 수열은 완성된 것이 아니라 M개의 숫자를 지정된 위치에 추가하면 완성된다고 한다.
완성된 수열에서 인덱스 L의 데이터를 출력하는 프로그램을 작성하시오.


[입력]

첫 줄에 테스트케이스의 수 T가 주어진다. 1<=T<=50
다음 줄부터 테스트 케이스의 별로 첫 줄에 수열의 길이 N, 추가 횟수 M, 출력할 인덱스 번호 L이 주어지고, 다음 줄에 수열이 주어진다.
그 다음 M개의 줄에 걸쳐 추가할 인덱스와 숫자 정보가 주어진다. 5<=N<=1000, 1<=M<=1000, 6<=L<=N+M

[출력]

각 줄마다 "#T" (T는 테스트 케이스 번호)를 출력한 뒤, 답을 출력한다.
"""

"""
사용 로직
1. 연결 리스트 구현
"""

class Node :
    data = -1
    next = None
    
class LinkedList :
    head = Node()
    
    def __init__(self) :
        self.head = Node()
    
    def put(self, data, position) :
        searchNode = self.head
        
        for _ in range(position) :
            searchNode = searchNode.next
        
        newNode = Node()
        newNode.data = data
        newNode.next = searchNode.next
        searchNode.next = newNode
        
    def get(self, position) :
        searchNode = self.head
        
        for _ in range(position) :
            searchNode = searchNode.next
        
        return searchNode.next.data

t = int(input())
tc = 1

while tc <= t :
    ans = 0
    n, m, l = (map(int, input().split()))
    numList = list(map(int, input().split()))
    linkedList = LinkedList()
    
    for i in range(len(numList)) :
        linkedList.put(numList[i], i)
    
    for i in range(m) :
        pos, data = (map(int, input().split()))
        linkedList.put(data, pos)
    
    ans = linkedList.get(l)
    print("#{} {}".format(tc, ans))
    tc += 1