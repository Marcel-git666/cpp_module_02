#include "Fixed.hpp"
#include <cmath>
#include <iostream>

Fixed::Fixed(void) {
    std::cout << "Default constructor called\n";
    _fixedPointValue = 0;
}

Fixed::Fixed(const Fixed &other) {
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
    float scaled = value * (1 << this->_fractionalBits);
    _fixedPointValue = static_cast<int>(roundf(scaled));
}

// Other methods

void Fixed::setRawBits(int const raw) { _fixedPointValue = raw; }

float Fixed::toFloat(void) const {
    return static_cast<float>(_fixedPointValue) /
           static_cast<float>(1 << _fractionalBits);
}

int Fixed::toInt(void) const { return _fixedPointValue >> _fractionalBits; }

// Operators

bool Fixed::operator>(Fixed const &other) const {
    return _fixedPointValue > other._fixedPointValue;
}

bool Fixed::operator<(Fixed const &other) const {
    return _fixedPointValue < other._fixedPointValue;
}

bool Fixed::operator>=(Fixed const &other) const {
    return _fixedPointValue >= other._fixedPointValue;
}

bool Fixed::operator<=(Fixed const &other) const {
    return _fixedPointValue <= other._fixedPointValue;
}

bool Fixed::operator==(Fixed const &other) const {
    return _fixedPointValue == other._fixedPointValue;
}

bool Fixed::operator!=(Fixed const &other) const {
    return _fixedPointValue != other._fixedPointValue;
}

Fixed Fixed::operator+(Fixed const &other) const {
    Fixed temp;
    temp.setRawBits(_fixedPointValue + other._fixedPointValue);
    return temp;
}

Fixed Fixed::operator-(Fixed const &other) const {
    Fixed temp;
    temp.setRawBits(_fixedPointValue - other._fixedPointValue);
    return temp;
}

Fixed Fixed::operator*(Fixed const &other) const {
    Fixed temp;
    long multiplication;
    multiplication = static_cast<long>(_fixedPointValue) * other._fixedPointValue >>
                     _fractionalBits;
    temp.setRawBits(multiplication);
    return temp;
}

Fixed Fixed::operator/(Fixed const &other) const {
    Fixed temp;
    long result = (static_cast<long>(_fixedPointValue) << _fractionalBits) /
                  other._fixedPointValue;
    temp.setRawBits(static_cast<int>(result));
    return Fixed(temp);
}

// pre
Fixed &Fixed::operator++(void) {
    _fixedPointValue++;
    return *this;
}

Fixed &Fixed::operator--(void) {
    _fixedPointValue--;
    return *this;
}
// post
Fixed Fixed::operator++(int) {
    Fixed temp;
    temp.setRawBits(_fixedPointValue++);
    return temp;
}

Fixed Fixed::operator--(int) {
    Fixed temp;
    temp.setRawBits(this->_fixedPointValue--);
    return temp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b) { return (a < b ? a : b); }

const Fixed &Fixed::min(Fixed const &a, Fixed const &b) {
    return (a < b ? a : b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b) { return (a > b ? a : b); }

const Fixed &Fixed::max(Fixed const &a, Fixed const &b) {
    return (a > b ? a : b);
}

std::ostream &operator<<(std::ostream &out, Fixed const &value) {
    return out << value.toFloat();
}
