#include <Python.h>
#include "rectangle.hpp"

typedef struct {
    PyObject_HEAD
    shapes::Rectangle* rect;
} RectangleObject;

static void
Rectangle_dealloc(RectangleObject* self)
{
    delete self->rect;
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
Rectangle_new(PyTypeObject* type, PyObject *args, PyObject *kwds)
{
    int x0, y0, x1, y1;
    if (!PyArg_ParseTuple(args, "iiii", &x0, &y0, &x1, &y1))
        return NULL;
    RectangleObject* self = (RectangleObject*) type->tp_alloc(type, 0);
    if(self!=NULL){
        self->rect = new shapes::Rectangle(x0, y0, x1, y1);
    }

    return (PyObject*)self;
}

static PyObject*
Rectangle_getLength(RectangleObject* self)
{
    return PyLong_FromLong(self->rect->getLength());
}

static PyObject*
Rectangle_getHeight(RectangleObject* self)
{
    return PyLong_FromLong(self->rect->getHeight());
}

static PyObject*
Rectangle_getArea(RectangleObject* self)
{
    return PyLong_FromLong(self->rect->getArea());
}

static PyObject*
Rectangle_move(RectangleObject* self, PyObject* args)
{
    int dx, dy;
    if(!PyArg_ParseTuple(args, "ii", &dx, &dy))
        return NULL;
    self->rect->move(dx, dy);

    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject*
Rectangle_repr(RectangleObject* self)
{
    return PyUnicode_FromFormat("Rectangle(%d, %d, %d, %d)",
                                self->rect->x0,
                                self->rect->y0,
                                self->rect->x1,
                                self->rect->y1);
}

static PyMethodDef Rectangle_methods[] = {
    {"getLength", (PyCFunction)Rectangle_getLength, METH_NOARGS, NULL},
    {"getHeight", (PyCFunction)Rectangle_getHeight, METH_NOARGS, NULL},
    {"getArea", (PyCFunction)Rectangle_getArea, METH_NOARGS, NULL},
    {"move", (PyCFunction)Rectangle_move, METH_VARARGS, NULL},
    {NULL}
};

static PyTypeObject RectangleType = {
    PyVarObject_HEAD_INIT(NULL, 0)
    "rect_cpp.Rectangle",      /* tp_name */
    sizeof(RectangleObject),   /* tp_basicsize */
    0,                         /* tp_itemsize */
    0,                         /* tp_dealloc */
    0,                         /* tp_print */
    0,                         /* tp_getattr */
    0,                         /* tp_setattr */
    0,                         /* tp_reserved */
    0,                         /* tp_repr */
    0,                         /* tp_as_number */
    0,                         /* tp_as_sequence */
    0,                         /* tp_as_mapping */
    0,                         /* tp_hash  */
    0,                         /* tp_call */
    0,                         /* tp_str */
    0,                         /* tp_getattro */
    0,                         /* tp_setattro */
    0,                         /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,        /* tp_flags */
    "Rectangle objects",       /* tp_doc */
};

static struct PyModuleDef module = {
   PyModuleDef_HEAD_INIT,
   "rect_cpp",
   NULL,
   -1,
   NULL
};

PyMODINIT_FUNC
PyInit_rect_cpp(void)
{
    PyObject* m = PyModule_Create(&module);

    if (m==NULL) return NULL;

    RectangleType.tp_new = Rectangle_new;
    RectangleType.tp_dealloc = (destructor)Rectangle_dealloc;
    RectangleType.tp_methods = Rectangle_methods;
    RectangleType.tp_repr = (reprfunc)Rectangle_repr;
    if (PyType_Ready(&RectangleType) < 0) return NULL;

    Py_INCREF(&RectangleType);
    PyModule_AddObject(m, "Rectangle", (PyObject*)&RectangleType);

    return m;
}
