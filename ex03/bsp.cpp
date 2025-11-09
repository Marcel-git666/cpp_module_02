
#include "Point.hpp"

Fixed getDeterminant(Point const p1, Point const p2, Point const p3) {
    Fixed determinant = (p1.getX() - p3.getX()) * (p2.getY() - p3.getY()) -
                        (p2.getX() - p3.getX()) * (p1.getY() - p3.getY());
    return determinant;
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
    Fixed res1, res2, res3;

    res1 = getDeterminant(a, b, point);
    res2 = getDeterminant(b, c, point);
    res3 = getDeterminant(c, a, point);

    if (res1 > 0 && res2 > 0 && res3 > 0)
        return true;
    else if (res1 < 0 && res2 < 0 && res3 < 0)
        return true;
    else
        return false;
}
