class Node:
   def __init__(self, dataval=None):
      self.data = dataval
      self.next = None

head = Node(50)


count=0
ite=head
while ite:
    count+=1
    ite=ite.next

if count%2==0:
    delete=count//2+1
else:
    count//2
i=0
while ite:
    if i==1:
        val1=ite.data
    if i==count-2:
        val2=ite.data
    ite=ite.next
    i+=1

va1,val2=val2,val1

i=0
if count ==1:
    head=None
else:
    while ite:
        if i==delete-1:
            ite.next=ite.next.next