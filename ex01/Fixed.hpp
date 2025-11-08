#ifndef FIXED_HPP
#define FIXED_HPP

#include <ostream>

class Fixed {
  private:
    int _fixedPointValue;
    static const int _fractionalBits = 8;

  public:
    // Orthodox Canonical Form
    Fixed(void);
    Fixed(const Fixed &other);
    Fixed &operator=(const Fixed &other);
    ~Fixed(void);

    Fixed(const int value);
    Fixed(const float value);

    // Other methods
    void setRawBits(int const raw);
    float toFloat(void) const;
    int toInt(void) const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &value);

#endif
