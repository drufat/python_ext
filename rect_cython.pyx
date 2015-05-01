cimport rect_h

cdef class Rectangle:
    # hold a C++ instance which we're wrapping
    cdef rect_h.Rectangle *thisptr 
    
    def __cinit__(self, int x0, int y0, int x1, int y1):
        self.thisptr = new rect_h.Rectangle(x0, y0, x1, y1)
    
    def __dealloc__(self):
        del self.thisptr
    
    def getLength(self):
        return self.thisptr.getLength()
    
    def getHeight(self):
        return self.thisptr.getHeight()
    
    def getArea(self):
        return self.thisptr.getArea()
    
    def move(self, dx, dy):
        self.thisptr.move(dx, dy)

