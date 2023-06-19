import ctypes
cops = ctypes.CDLL('./100-operations.so')

cops.add.argtypes = [ctypes.c_int, ctypes.c_int]
cops.add.restype = ctypes.c_int

cops.sub.argtypes = [ctypes.c_int, ctypes.c_int]
cops.sub.restype = ctypes.c_int

cops.mul.argtypes = [ctypes.c_int, ctypes.c_int]
cops.mul.restype = ctypes.c_int

cops.div.argtypes = [ctypes.c_int, ctypes.c_int]
cops.div.restype = ctypes.c_int

cops.mod.argtypes = [ctypes.c_int, ctypes.c_int]
cops.mod.restype = ctypes.c_int
a = 10
b = 5
result_add = cops.add(a, b)
result_sub = cops.sub(a, b)
result_mul = cops.mul(a, b)
result_div = cops.div(a, b)
result_mod = cops.mod(a, b)
print(f"{a} + {b} = {result_add}")
print(f"{a} - {b} = {result_sub}")
print(f"{a} x {b} = {result_mul}")
print(f"{a} / {b} = {result_div}")
print(f"{a} % {b} = {result_mod}")

