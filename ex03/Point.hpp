#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {
  private:
    const Fixed x;
    const Fixed y;

  public:
    // Orthodox Canonical Form
    Point(void);
    Point(float x_val, float y_val);
    Point(Point const &other);
    Point &operator=(Point const &other);
    ~Point(void);
    // getters
    Fixed getX(void) const;
    Fixed getY(void) const;
};

#endif
