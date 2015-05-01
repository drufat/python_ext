def test_rectangle():    

    from rect import Rectangle

    r = Rectangle(0, 0, 2, 3)
    assert r.getLength() == 2
    assert r.getHeight() == 3
    assert r.getArea() == 6
    r.move(3, 4)

def test_queue():
    
    from queue import Queue
    q = Queue()
    assert q.isempty()
    q.append(5)
    assert not q.isempty()
    assert q.peek() == 5
    assert q.pop() == 5
    assert q.isempty()
    q.extend((0,1,2,3))
    assert q.pop() == 0
    assert q.pop() == 1
    assert q.pop() == 2
    assert q.pop() == 3
    assert q.isempty()
    
    
def test_foo():

    from foo import Foo
    f = Foo(10)
    assert f.n == 10
    f.incr()
    assert f.n == 11