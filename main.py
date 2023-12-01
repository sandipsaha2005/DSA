# def seconLar(arr,arr_size):
#     arr.sort(reverse=True)
#     for i in range(1,arr_size-1):
#         if(arr[i]!=arr[0]):
#             print(f"the second largest number is {arr[i]}")
#             return
#     print("there is no second largest element")   

# arr=[2,3,5,7,89,89,0,90]
# arr_size=len(arr)
# seconLar(arr,arr_size)


# def secondLargest(arr,size):
#     arr.sort(reverse=True)

#     for i in range(1,size):
#         if(arr[i]!=arr[0]):
#             print(f"the second largest number is {arr[i]}")
#             return
#     print("there is no second largest nubmer present in the array")

# arr=[2,3,5,7,8,99,90,112,111]
# size=len(arr)
# secondLargest(arr,size)


# while(1):
#     print("hey")


# for letter in 'Python': # First Example
#  if letter == 'h':
#     continue
#  print ('Current Letter :', letter)
# var = 10 # Second Example
# while var > 0:
#  var = var -1
#  if var == 5:
#     continue
#  print ('Current variable value :', var)
# print ("Good bye!")

# for i in range(1,19):
#   if(i==5):
#     continue
#   print(f"the number is :{i}")


# def fib(n):
#     if(n<=0):
#         print("incorrect inpur")
#     elif(n==1):
#         return 0
#     elif (n==2):
#         return 1
#     else:
#         return fib(n-1)+fib(n-2)


# n=int(input("enter the lenth"))
# for i in range(1,n+1):
#     print(fib(i))


# def fact(n):
#     if(n==0):
#         return 0
#     elif (n==1):
#         return 1
#     else:
#         return n * fact(n-1)

# print(fact(5))


def sumOfArr(arr,lenght):
    sum=0
    for i in range(0,lenght):
        sum+=arr[i]
    print(f"the sum of the array is {sum}")


if __name__=="__main__":
    arr=[2,3,6,8,9]
    lenght=len(arr)
    sumOfArr(arr,lenght)





















