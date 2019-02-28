
class Node :
    data = 99999
    front = None
    prev = None
    
class DList :
    head = Node()
    tail = Node()
    head.prev = tail
    head.front = tail
    tail.prev = head
    tail.front = head

    def put(self, data, position=tail) :
        newNode = Node()
        newNode.data = data
        newNode.prev = position.prev
        newNode.front = position
        position.prev.front = newNode
        position.prev = newNode
        
    def step(self, m, k) :
        startNode = self.head
        
        while k >= 0 :
            for _ in range(m) :
                if startNode == self.head or startNode == self.tail : startNode = startNode.front
                startNode = startNode.front
            
            self.put(startNode.data + startNode.prev.data, startNode)
            k -= 1
    
    def printList(self) :
        searchNode = self.tail
        for _ in range(10) :
            if searchNode.prev == self.head : break
            
            print("{}".format(searchNode.prev.data), end=" ")
            searchNode = searchNode.prev
        print()
    
t = int(input())
tc = 1
        
while tc <= t :
    n, m, k = (map(int, input().split()))
    sList = list(map(int, input().split()))
    
    dlist = DList()
    length = len(sList)
    for i in range(length) :
        dlist.put(sList[i])
        
    dlist.step(m, k)    

    print("#{}".format(tc), end=" ")
    dlist.printList()
    tc += 1