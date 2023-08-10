#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

#define RED		"\e[0;31m" // Red
#define GREEN	"\e[0;32m" // Green
#define YELLOW	"\e[0;33m" // Yellow
#define BLUE	"\e[0;34m" // Blue
#define RESET 	"\e[0m"    // Reset

class Fixed
{
	private:
		int	num;
		static const int NUM_FRACTIONAL_BITS = 8;

	public:
		Fixed();
		Fixed(const int iNum);
		Fixed(const float fNum);
		~Fixed();
		Fixed(const Fixed& fixed);
		Fixed&	operator=(const Fixed& f);
		bool	operator>(const Fixed& f);
		bool	operator<(const Fixed& f);
		bool	operator>=(const Fixed& f);
		bool	operator<=(const Fixed& f);
		bool	operator==(const Fixed& f);
		bool	operator!=(const Fixed& f);
		Fixed&	operator+(const Fixed& f);
		Fixed&	operator-(const Fixed& f);
		Fixed&	operator*(const Fixed& f);
		Fixed&	operator/(const Fixed& f);
		Fixed&	operator++(void);
		Fixed	operator++(int);
		Fixed&	operator--(void);
		Fixed	operator--(int);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt( void ) const;
};

	std::ostream&	operator<<(std::ostream& os, const Fixed& fixed);
#endif
