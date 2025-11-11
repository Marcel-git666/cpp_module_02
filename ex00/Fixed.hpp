#ifndef FIXED_HPP
#define FIXED_HPP

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

    // Other methods
    int getRawBits(void) const;
    void setRawBits(int const raw);
};
#endif
