#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed(void) {
    std::cout << "Default constructor called\n";
    _fixedPointValue = 0;
}

Fixed::Fixed(Fixed const &other) {
    std::cout << "Copy constructor called\n";
    _fixedPointValue = other.getRawBits();
}

Fixed &Fixed::operator=(Fixed const &other) {
    std::cout << "Copy assignment operator called\n";
    if (this != &other) {
        _fixedPointValue = other.getRawBits();
    }
    return *this;
}

Fixed::~Fixed(void) { std::cout << "Destructor called\n"; }

// Other methods
int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called\n";
    return _fixedPointValue;
}

void Fixed::setRawBits(int const raw) { _fixedPointValue = raw; }
