#include "Python.h"
#include "foo.h"

extern "C"
void foo__cinit__(FooObject *self, int n)
{
    self->n = n;
}

extern "C"
void foo_incr(FooObject *self)
{
    self->n++;
}

