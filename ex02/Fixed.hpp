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

    // Operators
    bool operator>(Fixed const &other) const;
    bool operator<(Fixed const &other) const;
    bool operator>=(Fixed const &other) const;
    bool operator<=(Fixed const &other) const;
    bool operator==(Fixed const &other) const;
    bool operator!=(Fixed const &other) const;
    Fixed operator+(Fixed const &other) const;
    Fixed operator-(Fixed const &other) const;
    Fixed operator*(Fixed const &other) const;
    Fixed operator/(Fixed const &other) const;
    // pre
    Fixed &operator++(void);
    Fixed &operator--(void);
    // post
    Fixed operator++(int);
    Fixed operator--(int);

    // static

    static Fixed &min(Fixed &a, Fixed &b);
    static Fixed const &min(Fixed const &a, Fixed const &b);
    static Fixed &max(Fixed &a, Fixed &b);
    static Fixed const &max(Fixed const &a, Fixed const &b);
};

std::ostream &operator<<(std::ostream &out, Fixed const &value);

#endif
