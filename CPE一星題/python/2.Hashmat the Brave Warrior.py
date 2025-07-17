while(True):
    try:
        n=list(map(int,input().split()))
        
        s=sorted(n)
        #print(s)
        print(s[1]-s[0])

    except(EOFError):
        break
      
