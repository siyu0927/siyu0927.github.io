while(True):
    n=list(map(int,input().split()))
    

    if(n[0]==0 and n[1]==0):
        break

    
    a=n[0]
    b=n[1]

    carry=0
    c=0 #當前進位

    while a>0 or b>0:
        d=a%10+b%10+c
        if(d>=10):
            c=1
            carry+=1
        else:
            c=0
        
        a=a//10
        b=b//10

    if carry == 0:
     print("No carry operation.")
    elif carry == 1:
     print("1 carry operation.")
    else:
     print(f"{carry} carry operations.")
    
