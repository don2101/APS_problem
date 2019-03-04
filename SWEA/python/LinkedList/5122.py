"""
N개의 10억 이하 자연수로 이뤄진 수열이 주어진다. 이 수열은 완성된 것이 아니라 M번의 편집을 거쳐 완성된다고 한다.
완성된 수열에서 인덱스 L의 데이터를 출력하는 프로그램을 작성하시오.
다음은 미완성 수열과 편집의 예이다.

I 2 7 -> 2번 인덱스 앞에 7을 추가하고, 한 칸 씩 뒤로 이동한다.
D 4 -> 4번 인덱스 자리를 지우고, 한 칸 씩 앞으로 이동한다.
C 3 8 -> 3번 인덱스 자리를 8로 바꾼다.
만약 편집이 끝난 후 L이 존재하지 않으면 -1을 출력한다.

[입력]
첫 줄에 테스트케이스의 수 T가 주어진다. 1<=T<=50
다음 줄부터 테스트 케이스의 별로 첫 줄에 수열의 길이 N, 추가 횟수 M, 출력할 인덱스 번호 L이 주어지고, 다음 줄에 수열이 주어진다.
그 다음 M개의 줄에 걸쳐 추가할 인덱스와 숫자 정보가 주어진다. 5<=N<=1000, 1<=M<=1000, 6<=L<=N+M

[출력]
각 줄마다 "#T" (T는 테스트 케이스 번호)를 출력한 뒤, 답을 출력한다.


"""

class Node :
    data = -1
    next = None

class LinkedList :
    head = Node()
    size = 0
    
    def add(self, position, data) :
        newNode = Node()
        newNode.data = data
        
        searchNode = self.head
        for i in range(position) :
            searchNode = searchNode.next
        
        newNode.next = searchNode.next
        searchNode.next = newNode
        
        self.size += 1
        
    def delete(self, position) :
        searchNode = self.head
        for i in range(position) :
            searchNode = searchNode.next
        deleteNode = searchNode.next
        searchNode.next = deleteNode.next
        
        self.size -= 1
        
    def change(self, position, data) :
        searchNode = self.head
        for i in range(position) :
            searchNode = searchNode.next

        searchNode.next.data = data
        
    def search(self, position) :
        if self.size <= position : return -1
        searchNode = self.head
        for i in range(position) :
            searchNode = searchNode.next

        retData = searchNode.next.data
        return retData
        
t = int(input())
tc = 1

while tc <= t :
    ans = 0
    (n, m, l) = (map(int, input().split()))
    numbers = list(map(int, input().split()))
    linkedList = LinkedList()
    
    for i in range(n) :
        linkedList.add(i, numbers[i])
        
    for i in range(m) :
        operator = input().split()

        if operator[0] == 'I' :
            pos = int(operator[1])
            data = int(operator[2])
            linkedList.add(pos, data)
        elif operator[0] == 'D' :
            pos = int(operator[1])
            linkedList.delete(pos)
        elif operator[0] == 'C' :
            pos = int(operator[1])
            data = int(operator[2])
            linkedList.change(pos, data)
    
    ans = linkedList.search(l)    
    
    print("#{} {}".format(tc, ans))
    tc += 1