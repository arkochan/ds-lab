def encodeString(word,index,rand_num):
    if index>=len(word):
        return 0
    encLetter= chr((ord(word[index])+ rand_num - 97)%26 + 97)
    print(encLetter,end ="")
    encodeString(word,index+1,rand_num)

rand_num=20101010%26
encodeString(input(),0,rand_num)