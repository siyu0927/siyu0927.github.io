time=int(input())
for i in range(time):
    n=list(map(int,input().split()))
    s=sorted(n[1:])
    #print(s)
    mid=int(len(s)/2)
    #print(s[mid])
    total=0
    for j in s:
        total+=abs(j-s[mid])
        
    print(total)
       
