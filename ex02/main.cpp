#include "Fixed.hpp"

int main( void )
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << BLUE <<
	"[ Increment Test ]" <<
	RESET << std::endl;
	std::cout << "a  \t= " << a << std::endl;
	std::cout << "++a  \t= " << ++a << std::endl;
	std::cout << "a  \t= " << a << std::endl;
	std::cout << "a++  \t= " << a++ << std::endl;
	std::cout << "a  \t= " << a << std::endl;

	std::cout << BLUE <<
	"[ Decrement Test ]" <<
	RESET << std::endl;
	std::cout << "a  \t= " << a << std::endl;
	std::cout << "--a  \t= " << --a << std::endl;
	std::cout << "a  \t= " << a << std::endl;
	std::cout << "a--  \t= " << a-- << std::endl;
	std::cout << "a  \t= " << a << std::endl;

	std::cout << BLUE <<
	"[ Comparison Operators Test ]" <<
	RESET << std::endl;
	a = Fixed(10.01f);
	std::cout << "a  \t\t= " << a << std::endl;
	std::cout << "b  \t\t= " << b << std::endl;
	std::cout << "---" << std::endl;
	std::cout << "a > b  \t\t= " << (a > b) << std::endl;
	std::cout << "a < b  \t\t= " << (a < b) << std::endl;
	std::cout << "a >= b  \t= " << (a >= b) << std::endl;
	std::cout << "a <= b  \t= " << (a <= b) << std::endl;
	std::cout << "a == b  \t= " << (a == b) << std::endl;
	std::cout << "a != b  \t= " << (a != b) << std::endl;

	std::cout << BLUE <<
	"[ Arithmetic Operators Test ]" <<
	RESET << std::endl;
	a = Fixed(6);
	Fixed c(4);
	std::cout << "a  \t= " << a << std::endl;
	std::cout << "c  \t= " << c << std::endl;
	std::cout << "---" << std::endl;
	std::cout << "a + c \t= " << (a + c) << std::endl;
	std::cout << "a - c \t= " << (a - c) << std::endl;
	std::cout << "a * c \t= " << (a * c) << std::endl;
	std::cout << "a / c \t= " << (a / c) << std::endl;

	std::cout << BLUE <<
	"[ Max & Min Test ]" <<
	RESET << std::endl;

	Fixed const d( Fixed( 5.05f ) * Fixed( 1.98f ) );
	c = Fixed(6.1f);
	std::cout << "mutable  a  \t= " << a << std::endl;
	std::cout << "imutable b  \t= " << b << std::endl;
	std::cout << "mutable  c  \t= " << c << std::endl;
	std::cout << "imutable d  \t= " << d << std::endl;
	std::cout << "---" << std::endl;
	std::cout << "max(a, c) \t= " << Fixed::max( a, c ) << std::endl;
	std::cout << "min(a, c) \t= " << Fixed::min( a, c ) << std::endl;
	std::cout << "max(b, d) \t= " << Fixed::max( b, d ) << std::endl;
	std::cout << "min(b, d) \t= " << Fixed::min( b, d ) << std::endl;
	return 0;
}
