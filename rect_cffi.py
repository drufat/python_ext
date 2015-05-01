import os
from cffi import FFI
ffi = FFI()

with open(os.environ['RECTANGLE_H'], 'r') as f:
    ffi.cdef(f.read())
C = ffi.dlopen(os.environ['RECTANGLE_CFFI_SO'])

class Rectangle:
    
    def __init__(self, x0, y0, x1, y1):
        self.thisptr = C.rect_new(x0, y0, x1, y1)
    
    def __dealloc__(self):
        C.rect_del(self.thisptr)
    
    def getLength(self):
        return C.rect_getLength(self.thisptr)
    
    def getHeight(self):
        return C.rect_getHeight(self.thisptr)
    
    def getArea(self):
        return C.rect_getArea(self.thisptr)
    
    def move(self, dx, dy):
        C.rect_move(self.thisptr, dx, dy)

