#include "Fixed.hpp"
#include <cmath>
#include <iostream>

Fixed::Fixed(void) { this->_fixedPointValue = 0; }

Fixed::Fixed(const Fixed &other) {
    this->_fixedPointValue = other._fixedPointValue;
}

Fixed &Fixed::operator=(const Fixed &other) {
    if (this != &other) {
        this->_fixedPointValue = other._fixedPointValue;
    }
    return *this;
}

Fixed::~Fixed(void) {}

Fixed::Fixed(const int value) {
    this->_fixedPointValue = value << this->_fractionalBits;
}

Fixed::Fixed(const float value) {
    float scaled = value * (1 << this->_fractionalBits);
    this->_fixedPointValue = static_cast<int>(roundf(scaled));
}

// Other methods

void Fixed::setRawBits(int const raw) { this->_fixedPointValue = raw; }

float Fixed::toFloat(void) const {
    return (float)this->_fixedPointValue / (float)(1 << this->_fractionalBits);
}

int Fixed::toInt(void) const {
    return (int)this->_fixedPointValue >> _fractionalBits;
}

// Operators

bool Fixed::operator>(const Fixed &other) const {
    return this->_fixedPointValue > other._fixedPointValue;
}

bool Fixed::operator<(const Fixed &other) const {
    return this->_fixedPointValue < other._fixedPointValue;
}

bool Fixed::operator>=(const Fixed &other) const {
    return this->_fixedPointValue >= other._fixedPointValue;
}

bool Fixed::operator<=(const Fixed &other) const {
    return this->_fixedPointValue <= other._fixedPointValue;
}

bool Fixed::operator==(const Fixed &other) const {
    return this->_fixedPointValue == other._fixedPointValue;
}

bool Fixed::operator!=(const Fixed &other) const {
    return this->_fixedPointValue != other._fixedPointValue;
}

Fixed Fixed::operator+(const Fixed &other) const {
    Fixed temp;
    temp.setRawBits(this->_fixedPointValue + other._fixedPointValue);
    return temp;
}

Fixed Fixed::operator-(const Fixed &other) const {
    Fixed temp;
    temp.setRawBits(this->_fixedPointValue - other._fixedPointValue);
    return temp;
}

Fixed Fixed::operator*(const Fixed &other) const {
    Fixed temp;
    long multiplication;
    multiplication = (long)this->_fixedPointValue * other._fixedPointValue >>
                     this->_fractionalBits;
    temp.setRawBits(multiplication);
    return temp;
}

Fixed Fixed::operator/(const Fixed &other) const {
    Fixed temp;
    long result = ((long)this->_fixedPointValue << this->_fractionalBits) /
                  other._fixedPointValue;
    temp.setRawBits((int)result);
    return Fixed(temp);
}

// pre
Fixed &Fixed::operator++(void) {
    this->_fixedPointValue++;
    return *this;
}

Fixed &Fixed::operator--(void) {
    this->_fixedPointValue--;
    return *this;
}
// post
Fixed Fixed::operator++(int) {
    Fixed temp;
    temp.setRawBits(this->_fixedPointValue++);
    return temp;
}

Fixed Fixed::operator--(int) {
    Fixed temp;
    temp.setRawBits(this->_fixedPointValue--);
    return temp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b) { return (a < b ? a : b); }

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
    return (a < b ? a : b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b) { return (a > b ? a : b); }

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
    return (a > b ? a : b);
}

std::ostream &operator<<(std::ostream &out, const Fixed &value) {
    return out << value.toFloat();
}
