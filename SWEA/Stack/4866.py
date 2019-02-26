tc = int(input())

stack = ['0'] * 1000
top = -1

for t in range(1, tc+1) :
    ans = 1
    string = input()
    top = -1
    
    for i in range(0, len(string)) :
        if string[i] == '(' or string[i] == '{' : 
            top += 1
            stack[top] = string[i]
        elif string[i] == '}' :
            ret = stack[top]
            top -= 1
            if ret != '{' :
                ans = 0
                break
        elif string[i] == ')' :
            ret = stack[top]
            top -= 1
            if ret != '(' :
                ans = 0
                break
                
    if top > -1 : ans = 0
    print("#{} {}".format(t, ans))