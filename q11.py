n = int(input("Enter the value of n: "))
val = 1

for i in range(n):
    for j in range(i+1):
        print(val, end=" ")
        val = val+1;
    print("\n")