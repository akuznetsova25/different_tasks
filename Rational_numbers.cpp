#include "ratio.hpp"

namespace math
{
	void Ratio::reduce()
	{
		verify();

		auto gcd = std::gcd(m_numerator, m_denominator); // C++17

		m_numerator   /= gcd;
		m_denominator /= gcd;
	}

	void Ratio::verify()
	{
		if (m_denominator < 0)
		{
			m_numerator   *= -1;
			m_denominator *= -1;
		}
	}

	std::ostream & operator<<(std::ostream & stream, const Ratio & ratio)
	{
		if (ratio.m_denominator == 1)
		{
			stream << ratio.m_numerator;
		}
		else
		{
			stream << ratio.m_numerator << '/' << ratio.m_denominator;
		}

		return stream;
	}

	std::istream & operator>>(std::istream & stream, Ratio & ratio)
	{
		char c;

		stream >> ratio.m_numerator >> c >> ratio.m_denominator;

		ratio.reduce();

		return stream;
	}

	Ratio & Ratio::operator+=(const Ratio & other)
	{
		m_numerator   = m_numerator   * other.m_denominator + m_denominator * other.m_numerator;
		m_denominator = m_denominator * other.m_denominator;

		reduce();

		return *this;
	}

	Ratio & Ratio::operator-=(const Ratio & other)
	{
		m_numerator   = m_numerator   * other.m_denominator - m_denominator * other.m_numerator;
		m_denominator = m_denominator * other.m_denominator;

		reduce();

		return *this;
	}

	Ratio & Ratio::operator*=(const Ratio & other)
	{
		m_numerator   *= other.m_numerator;
		m_denominator *= other.m_denominator;

		reduce();

		return *this;
	}

	Ratio & Ratio::operator/=(const Ratio & other)
	{
		m_numerator   *= other.m_denominator;
		m_denominator *= other.m_numerator;

		reduce();

		return *this;
	}

	Ratio & Ratio::operator++()
	{
		*this += 1;
		return *this;
	}

	Ratio & Ratio::operator--()
	{
		*this -= 1;
		return *this;
	}

	Ratio Ratio::operator++(int)
	{
		Ratio copy(*this);
		++(*this);
		return copy;
	}

	Ratio Ratio::operator--(int)
	{
		Ratio copy(*this);
		--(*this);
		return copy;
	}

	bool operator==(const Ratio & lhs, const Ratio & rhs)
	{
		return (lhs.m_numerator == rhs.m_numerator && lhs.m_denominator == rhs.m_denominator);
	}

	bool operator!=(const Ratio & lhs, const Ratio & rhs)
	{
		return !(lhs == rhs);
	}

	bool operator<(const Ratio & lhs, const Ratio & rhs)
	{
		return (lhs.m_numerator * rhs.m_denominator < rhs.m_numerator* lhs.m_denominator);
	}

	bool operator>(const Ratio & lhs, const Ratio & rhs)
	{
		return !((lhs == rhs) || (lhs < rhs));
	}

	bool operator<=(const Ratio & lhs, const Ratio & rhs)
	{
		return !(lhs > rhs);
	}

	bool operator>=(const Ratio & lhs, const Ratio & rhs)
	{
		return !(lhs < rhs);
	}

	Ratio operator+(const Ratio & lhs, const Ratio & rhs)
	{
		Ratio result(lhs);
		result += rhs;
		return result;
	}

	Ratio operator-(const Ratio & lhs, const Ratio & rhs)
	{
		Ratio result(lhs);
		result -= rhs;
		return result;
	}

	Ratio operator*(const Ratio & lhs, const Ratio & rhs)
	{
		Ratio result(lhs);
		result *= rhs;
		return result;
	}

	Ratio operator/(const Ratio & lhs, const Ratio & rhs)
	{
		Ratio result(lhs);
		result /= rhs;
		return result;
	}
}
