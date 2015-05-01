from cffi import FFI
ffi = FFI()

ffi.cdef('''
    typedef void* CRectangle;
    
    CRectangle rect_new(int x0, int y0, int x1, int y1);
    void rect_del(CRectangle r);
    int rect_getLength(CRectangle r);
    int rect_getHeight(CRectangle r);
    int rect_getArea(CRectangle r);
    void rect_move(CRectangle r, int dx, int dy);
''')

import os
C = ffi.dlopen(os.environ['RECTANGLE_CFFI'])

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

