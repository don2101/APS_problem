t = int(input())

tc = 1
stack = [0] * 1000

while tc <= t :
    ans = 0
    string = list(map(str, input().split()))
    top = -1

    for i in range(0, len(string)-1) :
        if string[i] == '*' :
            if(top < 1) : ans = 'error'; break
            num2 = stack[top]
            top -= 1
            num1 = stack[top]
            stack[top] = num1 * num2
        elif string[i] == '/' : 
            if(top < 1) : ans = 'error'; break
            num2 = stack[top]
            top -= 1
            num1 = stack[top]
            stack[top] = int(num1 / num2)
        elif string[i] == '+' : 
            if(top < 1) : ans = 'error'; break
            num2 = stack[top]
            top -= 1
            num1 = stack[top]
            stack[top] = num1 + num2
        elif string[i] == '-' : 
            if(top < 1) : ans = 'error'; break
            num2 = stack[top]
            top -= 1
            num1 = stack[top]
            stack[top] = num1 - num2    
        else :
            top += 1
            stack[top] = int(string[i])
    
    if(top == 0 and ans != 'error') :
        ans = stack[top]
    else :
        ans = 'error'

    print("#{} {}".format(tc, ans))
    tc += 1
    