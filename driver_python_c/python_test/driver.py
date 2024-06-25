from ctypes import *

# print(cdll.msvcrt)

my_functions = cdll.LoadLibrary("./my_functions.so")

print(type(my_functions))
print(my_functions.sum(4, 1000*1000*1000))

print("Done")
