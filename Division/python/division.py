import sys

try:
    number1 = int(input("Введи число А: "))
    number2 = int(input("Введи число Б: "))
    print("Divider result:", number1/number2)
except ZeroDivisionError:
    print("Делить на 0 нельзя!")
print("The end of program!")
print(sys.getsizeof(int))
print(sys.getsizeof(float))
