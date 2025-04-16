num = int(input("Enter a number to check it is palindrome or not: "))
rev = 0
copyNum = num

while(copyNum != 0):
    rev = (rev*10)+(copyNum%10)
    copyNum //= 10;

if(num == rev):
    print("It is Plaindrom number")

else:
    print("Not a palindrom number")