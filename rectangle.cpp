#include "rectangle.hpp"
#include "rectangle.h"

using namespace shapes;

Rectangle::Rectangle(int X0, int Y0, int X1, int Y1)
{
    x0 = X0;
    y0 = Y0;
    x1 = X1;
    y1 = Y1;
}

Rectangle::~Rectangle()
{
}

int Rectangle::getLength()
{
    return (x1 - x0);
}

int Rectangle::getHeight()
{
    return (y1 - y0);
}

int Rectangle::getArea()
{
    return (x1 - x0) * (y1 - y0);
}

void Rectangle::move(int dx, int dy)
{
    x0 += dx;
    y0 += dy;
    x1 += dx;
    y1 += dy;
}


// C wrapper around the above C++ class

CRectangle rect_new(int x0, int y0, int x1, int y1){
    return reinterpret_cast<CRectangle>(new Rectangle(x0, y0, x1, y1));
}

void rect_del(CRectangle r){
    delete reinterpret_cast<Rectangle*>(r);
}

int rect_getLength(CRectangle r)
{
    return reinterpret_cast<Rectangle*>(r)->getLength();
}

int rect_getHeight(CRectangle r)
{
    return reinterpret_cast<Rectangle*>(r)->getHeight();
}

int rect_getArea(CRectangle r)
{
    return reinterpret_cast<Rectangle*>(r)->getArea();
}

void rect_move(CRectangle r, int dx, int dy)
{
    reinterpret_cast<Rectangle*>(r)->move(dx, dy);
}
