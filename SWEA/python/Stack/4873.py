tc = int(input())

stack = [0] * 1001
top = -1

for t in range(1, tc+1) :
    string = input()
    ans = 0
    top = 0
    stack[top] = string[0]
    
    for i in range(1, len(string)) :
        if(string[i] == stack[top]) :
            top -= 1
        else :
            top += 1
            stack[top] = string[i]
    ans = top + 1
    print("#{} {}".format(t, ans))
    