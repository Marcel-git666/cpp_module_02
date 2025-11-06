#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed(void) {
    std::cout << "Default constructor called\n";
    this->_fixedPointValue = 0;
}

Fixed::Fixed(const Fixed &other) {
    std::cout << "Copy constructor called\n";
    this->_fixedPointValue = other.getRawBits();
}

Fixed &Fixed::operator=(const Fixed &other) {
    std::cout << "Copy assignment operator called\n";
    if (this != &other) {
        this->_fixedPointValue = other.getRawBits();
    }
    return *this;
}

Fixed::~Fixed(void) { std::cout << "Destructor called\n"; }

// Other methods
int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called\n";
    return this->_fixedPointValue;
}

void Fixed::setRawBits(int const raw) { this->_fixedPointValue = raw; }
