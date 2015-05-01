cimport queue_h

cdef class Queue:
    """A queue class for C integer values.

    >>> q = Queue()
    >>> q.append(5)
    >>> q.peek()
    5
    >>> q.pop()
    5
    """
    cdef queue_h.Queue* _c_queue
    def __cinit__(self):
        self._c_queue = queue_h.queue_new()
        if self._c_queue is NULL:
            raise MemoryError()

    def __dealloc__(self):
        if self._c_queue is not NULL:
            queue_h.queue_free(self._c_queue)

    def isempty(self):
        return queue_h.queue_is_empty(self._c_queue)

    def __bool__(self):
        return not queue_h.queue_is_empty(self._c_queue)

    cpdef append(self, int value):
        if not queue_h.queue_push_tail(self._c_queue,
                                      <void*>value):
            raise MemoryError()

    cdef c_extend(self, int* values, size_t count):
        cdef size_t i
        for i in range(count):
            if not queue_h.queue_push_tail(
                    self._c_queue, <void*>values[i]):
                raise MemoryError()
    
    cpdef extend(self, values):
        for value in values:
            self.append(value)

    cpdef int peek(self) except? -1:
        cdef int value = \
            <int>queue_h.queue_peek_head(self._c_queue)
        if value == 0:
            # this may mean that the queue is empty,
            # or that it happens to contain a 0 value
            if queue_h.queue_is_empty(self._c_queue):
                raise IndexError("Queue is empty")
        return value

    cpdef int pop(self) except? -1:
        if queue_h.queue_is_empty(self._c_queue):
            raise IndexError("Queue is empty")
        return <int>queue_h.queue_pop_head(self._c_queue)

