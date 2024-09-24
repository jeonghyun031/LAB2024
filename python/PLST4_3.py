print("정수를 입력하세요>> ")

n = int(input())

sum = 0
for i in range(1, n+1):
    sum += i # sum에 i를 더함
    
print("1부터", n, "까지의 합 = ", sum)