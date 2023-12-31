#include "Fixed.hpp"
#include <stdio.h>

Fixed::Fixed()
{
	// std::cout << "Default constructor called" << std::endl;
	this->num = 0;
}

Fixed::Fixed(const int iNum)
{
	// std::cout << "Int constructor called" << std::endl;
	this->num = iNum * (1 << NUM_FRACTIONAL_BITS);
}

Fixed::Fixed(const float fNum)
{
	// std::cout << "Float constructor called" << std::endl;
	this->num = std::roundf(fNum * (1 << NUM_FRACTIONAL_BITS));
}

Fixed::Fixed(const Fixed& fixed)
{
	// std::cout << "Copy constructor called" << std::endl;
	this->setRawBits(fixed.num);
}

Fixed& Fixed::operator=(const Fixed& f)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this == &f)
		return *this;
	this->num = f.getRawBits();
	return *this;
}

bool Fixed::operator>(const Fixed& f) const
{
	return this->getRawBits() > f.getRawBits();
}

bool Fixed::operator<(const Fixed& f) const
{
	return this->getRawBits() < f.getRawBits();
}

bool Fixed::operator>=(const Fixed& f) const
{
	return this->getRawBits() >= f.getRawBits();
}

bool Fixed::operator<=(const Fixed& f) const
{
	return this->getRawBits() <= f.getRawBits();
}

bool Fixed::operator==(const Fixed& f) const
{
	return this->getRawBits() == f.getRawBits();
}

bool Fixed::operator!=(const Fixed& f) const
{
	if (this->num != f.getRawBits())
		return true;
	return false;
}

Fixed Fixed::operator+(const Fixed& f)
{
	return  Fixed(this->toFloat() + f.toFloat());
}

Fixed Fixed::operator-(const Fixed& f)
{
	return  Fixed(this->toFloat() - f.toFloat());
}

Fixed Fixed::operator*(const Fixed& f)
{
	return  Fixed(this->toFloat() * f.toFloat());
}

Fixed Fixed::operator/(const Fixed& f)
{
	return  Fixed(this->toFloat() / f.toFloat());
}

Fixed& Fixed::operator++(void)
{
	this->num++;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed temp = *this;
	++*this;
	return temp;
}

Fixed& Fixed::operator--(void)
{
	this->num--;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed temp = *this;
	--*this;
	return temp;
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

int		Fixed::getRawBits(void) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return this->num;
}

void	Fixed::setRawBits(int const raw)
{
	this->num = raw;
}

float	Fixed::toFloat(void) const
{
	return static_cast<float>(this->getRawBits()) / (1 << this->NUM_FRACTIONAL_BITS);
}

int		Fixed::toInt(void) const
{
	return this->num / (1 << this->NUM_FRACTIONAL_BITS);
}

Fixed&	Fixed::min(Fixed& f1, Fixed& f2)
{
	return f1 < f2 ? f1 : f2;
}

const Fixed&	Fixed::min(const Fixed& f1, const Fixed& f2)
{
	return f1 < f2 ? f1 : f2;
}


Fixed&	Fixed::max(Fixed& f1, Fixed& f2)
{
	return f1 > f2 ? f1 : f2;
}

const Fixed&	Fixed::max(const Fixed& f1, const Fixed& f2)
{
	return f1 > f2 ? f1 : f2;
}

std::ostream&	operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return os;
}
