


def B_search(a, num):
    l = 0
    u = len(a)-1
    c = 0
    
    if num>a[len(a)-1]:
        return len(a)
    mid = (l+u)//2

    while l<=u:
        
        mid = (l+u)//2
        #print(l, mid, u)
        
        if a[mid] == num:
             c = mid+1
             return c
       
        else:
            
            if num < a[mid]:
                u = mid-1
              
            else:
                l = mid+1
    if a[mid]>=num:
        return mid
    if a[mid]<num:
        return mid+1

  
    
        
     
    
N1 = 4
N2 = 3    
A1 = [1,3,5,7,9]
A2 = [int(input())]
A3 = [0]*3

for i in range(len(A2)):
    element = B_search(A1, A2[i])
    print (element)
