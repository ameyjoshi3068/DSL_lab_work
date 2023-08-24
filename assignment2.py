# The function to return list of individual words separated from string
def splitWords(s):
    wordList=[]
    firstIndex=0
    lastIndex=0
    for i in s:
        if i!=" ":
            lastIndex+=1
        else:
            wordList.append(s[firstIndex:lastIndex])
            firstIndex=lastIndex+1
            lastIndex+=1
    wordList.append(s[firstIndex:lastIndex])
    return wordList
            
# The function to return longest word in the string
def longestWord(l):
    max=0
    maxWords=[]
    for i in l:
        counter=0
        for _ in i:
            counter+=1
        if counter>max:
            max=counter
    for i in l:
        counter=0
        for _ in i:
            counter+=1
        if counter==max:
            maxWords.append(i)

    count=0
    for i in maxWords:
        count+=1


    return count,maxWords,max

# the function to return frequency of individual character in string
def frequency(s,c):
    count=0
    for i in s:
        if i==c:
            count+=1

    return count

# The function to check the string for palindrome
def chkPalindrome(s):
    if s[::-1]==s:
        return True
    else:
        return False
    
# The function to find first occurrence of substring
def firstIndex(s,c):
    for i in range(len(s)):
        if s[i]==c[0]:
            passed=True
            for j in range(len(c)):
                if s[i+j]!=c[j]:
                    passed=False
            if passed==True:
                return i
    return -1
            
# Function to find frequency of every word in the substring
def countWord(l):
    frequency={}
    for i in l:
        count=0
        for j in l:
            if j==i:
                count+=1
        frequency[i]=count
    return frequency
    


s=input("Enter the string on which operations are to be performed: ")
l=splitWords(s)

index=9

while index!=0:
    print("Please select an option by entering corresponding index and 0 to quit\n")
    print("1) To display word with the longest length")
    print("2) To determines the frequency of occurrence of particular character in the string")
    print("3) To check whether given string is palindrome or not")
    print("4) To display index of first appearance of the substring")
    print("5) To count the occurrences of each word in a given string")

    index=input("Select an option: ")
    try:
        index=int(index)
    except:
        print("Invalid Selection \n\n")
        continue

    if index==1:
        count,maxWords,max=longestWord(l)
        print (f"There are {count} words with maximum {max} characters in the string: {maxWords}")
        print("\n\n\n")
    elif index==2:
        c=input("Enter the character to check: ")
        print (f"The frequency of occurrence of character {c} in the string:",frequency(s,c))
        print("\n\n\n")
    elif index==3:
        ans=chkPalindrome(s)
        if ans:
            print("The string is a palindrome")

        else :
            print("The string is not a palindrome")
        print("\n\n\n")

    elif index==4:
        c=input("Enter the substring: ")
        print (f"first appearance of the substring {c} is index: ",firstIndex(s,c))
        print("\n\n\n")

    elif index==5:
        print ("The occurrence of each word in the string is:\n",countWord(l))
        print("\n")

    elif index==0:
        break
    else:
        print("Invalid Selection \n\n")
    