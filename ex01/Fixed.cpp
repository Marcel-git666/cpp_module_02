#include "Fixed.hpp"
#include <cmath>
#include <iostream>

Fixed::Fixed(void) {
    std::cout << "Default constructor called\n";
    _fixedPointValue = 0;
}

Fixed::Fixed(Fixed const &other) {
    std::cout << "Copy constructor called\n";
    _fixedPointValue = other._fixedPointValue;
}

Fixed &Fixed::operator=(Fixed const &other) {
    std::cout << "Copy assignment operator called\n";
    if (this != &other) {
        _fixedPointValue = other._fixedPointValue;
    }
    return *this;
}

Fixed::~Fixed(void) { std::cout << "Destructor called\n"; }

Fixed::Fixed(int const value) {
    std::cout << "Int constructor called\n";
    _fixedPointValue = value << _fractionalBits;
}

Fixed::Fixed(float const value) {
    std::cout << "Float constructor called\n";
    float scaled = value * (1 << _fractionalBits);
    _fixedPointValue = static_cast<int>(roundf(scaled));
}

// Other methods
int Fixed::getRawBits(void) const { return _fixedPointValue; }

void Fixed::setRawBits(int const raw) { _fixedPointValue = raw; }

float Fixed::toFloat(void) const {
    return static_cast<float>(_fixedPointValue) /
           static_cast<float>(1 << _fractionalBits);
}

int Fixed::toInt(void) const { return _fixedPointValue / (1 << _fractionalBits); }

std::ostream &operator<<(std::ostream &out, Fixed const &value) {
    return out << value.toFloat();
}
