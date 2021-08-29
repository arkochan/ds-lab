def reverseEncryption(message,key,ind):
    if ind>=len(message):
        return    
    reverseEncryption(message,key,ind+1)
    print( chr((ord(message[ind]) + key-65) % 26 + 65),end ="")
    

message = input("Meassage: ")
key=int(input("Key: "))
print("Reverse Encrypted Message: ",end="")
reverseEncryption(message,key,0)