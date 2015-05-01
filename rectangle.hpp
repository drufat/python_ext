#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

namespace shapes {

    class Rectangle {

    public:
        int x0, y0, x1, y1;
        Rectangle(int x0, int y0, int x1, int y1);
        ~Rectangle();
        int getLength();
        int getHeight();
        int getArea();
        void move(int dx, int dy);
    };
}

#endif
