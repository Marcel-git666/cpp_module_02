#ifndef FIXED_HPP
#define FIXED_HPP

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

    // Other methods
    int getRawBits(void) const;
    void setRawBits(int const raw);
};
#endif
