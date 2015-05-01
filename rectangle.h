#ifndef RECTANGLE_H
#define RECTANGLE_H

#ifdef __cplusplus
extern "C" {
#endif

typedef void* CRectangle;

CRectangle rect_new(int x0, int y0, int x1, int y1);
void rect_del(CRectangle r);
int rect_getLength(CRectangle r);
int rect_getHeight(CRectangle r);
int rect_getArea(CRectangle r);
void rect_move(CRectangle r, int dx, int dy);

#ifdef __cplusplus
}
#endif

#endif
