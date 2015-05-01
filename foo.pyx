# declare the functions
cdef extern void foo__cinit__(Foo self, int n)
cdef extern void foo_incr(Foo self)

cdef public class Foo [object FooObject, type FooType]:
    cdef int n

    def __cinit__(self, int n): foo__cinit__(self, n)
    def incr(self): foo_incr(self)

    property n:
        def __get__(self):
            return self.n
