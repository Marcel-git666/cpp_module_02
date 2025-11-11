#ifndef FIXED_HPP
#define FIXED_HPP

#include <ostream>

class Fixed {
  private:
    int _fixedPointValue;
    static int const _fractionalBits = 8;

  public:
    // Orthodox Canonical Form
    Fixed(void);
    Fixed(Fixed const &other);
    Fixed &operator=(Fixed const &other);
    ~Fixed(void);

    Fixed(int const value);
    Fixed(float const value);

    // Other methods
    int getRawBits(void) const;
    void setRawBits(int const raw);
    float toFloat(void) const;
    int toInt(void) const;
};

std::ostream &operator<<(std::ostream &out, Fixed const &value);

#endif
