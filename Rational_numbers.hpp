#pragma once

#include <istream>
#include <numeric>
#include <ostream>

namespace math
{
	class Ratio
	{
	public:

		Ratio() :
			m_numerator(0), m_denominator(1)
		{}

		Ratio(int numerator, int denumerator = 1) :
			m_numerator(numerator), m_denominator(denumerator)
		{
			reduce();
		}

		~Ratio() = default;

	private:

		void reduce();

		void verify(); // 1/-2 -> -1/2

	public:

		explicit operator double() const
		{
			return static_cast < double > (m_numerator) / static_cast < double > (m_denominator);
		}

	public:

		auto numerator() const
		{
			return m_numerator;
		}

		auto denominator() const
		{
			return m_denominator;
		}

	public:

		friend std::ostream & operator<<(std::ostream & stream, const Ratio & ratio);
		friend std::istream & operator>>(std::istream & stream,       Ratio & ratio);

	public:

		Ratio & operator+=(const Ratio & other);
		Ratio & operator-=(const Ratio & other);
		Ratio & operator*=(const Ratio & other);
		Ratio & operator/=(const Ratio & other);

	public:

		Ratio & operator++();
		Ratio & operator--();

		Ratio   operator++(int);
		Ratio   operator--(int);

	public:

		friend bool operator==(const Ratio & lhs, const Ratio & rhs);
		friend bool operator!=(const Ratio & lhs, const Ratio & rhs);
		friend bool operator< (const Ratio & lhs, const Ratio & rhs);
		friend bool operator> (const Ratio & lhs, const Ratio & rhs);
		friend bool operator>=(const Ratio & lhs, const Ratio & rhs);
		friend bool operator<=(const Ratio & lhs, const Ratio & rhs);

	private:

		int m_numerator;
		int m_denominator;
	};

	Ratio operator+(const Ratio & lhs, const Ratio & rhs);
	Ratio operator-(const Ratio & lhs, const Ratio & rhs);
	Ratio operator*(const Ratio & lhs, const Ratio & rhs);
	Ratio operator/(const Ratio & lhs, const Ratio & rhs);
}