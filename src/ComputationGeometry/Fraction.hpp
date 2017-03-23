/***
 * Copyright 2017 orangebird.
 * This file is published under MIT licence.
**/
#ifndef FRACTION_HPP
#define FRACTION_HPP
#include<iostream>
namespace orange_algo::math
{
	template <class T>
	T gcd(T a, T b)
	{
		if (a < 0)a = -a;
		if (b < 0)b = -b;
		while (b)
		{
			int t = a%b;
			a = b;
			b = t;
		}
		return a;
	}
	template <class T>
	class Fraction
	{
	public:
		T n, d;
		Fraction() { n = 0, d = 1; }
		Fraction(const Fraction& f)
		{
			n = f.n;
			d = f.d;
		}
		Fraction(const T& n_) :n(n_) { d = 1; }
		Fraction(const T& n_, const T& d_) :n(n_), d(d_) {}
		double toDouble()
		{
			return (double)n / (double)d;
		}
		Fraction reduce()
		{
			if (n == 0 && d != 0)
			{
				d = 1;
				return *this;
			}
			T t = gcd(n, d);
			n /= t;
			d /= t;
			if (n < 0 && d < 0)
			{
				n = -n;
				d = -d;
			}
			return *this;
		}
		Fraction& operator =(const Fraction& rhs)
		{
			n = rhs.n;
			d = rhs.d;
			return *this;
		}
		Fraction operator +(const Fraction& rhs)const
		{
			Fraction res;
			res.n = n*rhs.d + d*rhs.n;
			res.d = d*rhs.d;
			return res.reduce();
		}
		const Fraction operator +=(const Fraction& rhs)
		{
			n = n*rhs.d + d*rhs.n;
			d = d*rhs.d;
			return this->reduce();
		}
		Fraction operator -(const Fraction& rhs)const
		{
			Fraction res;
			res.n = n*rhs.d - d*rhs.n;
			res.d = d*rhs.d;
			return res.reduce();
		}
		const Fraction operator -=(const Fraction& rhs)
		{
			n = n*rhs.d - d*rhs.n;
			d = d*rhs.d;
			return this->reduce();
		}
		Fraction operator *(const Fraction& rhs)const
		{
			Fraction res;
			res.n = n*rhs.n;
			res.d = d*rhs.d;
			return res.reduce();
		}
		const Fraction operator *=(const Fraction& rhs)
		{
			n = n*rhs.n;
			d = d*rhs.d;
			return this->reduce();
		}
		template <class U>
		const Fraction operator *=(const U& rhs)
		{
			n *= rhs;
			return this->reduce();
		}
		Fraction operator /(const Fraction& rhs)const
		{
			Fraction res;
			res.n = n*rhs.d;
			res.d = d*rhs.n;
			return res.reduce();
		}
		const Fraction operator /=(const Fraction& rhs)
		{
			n = n*rhs.d;
			d = d*rhs.n;
			return this->reduce();
		}
	};
	template <class T>
	std::ostream& operator <<(std::ostream& os, Fraction<T> Frc)
	{
		if (Frc.d == 1)
			return os << Frc.n;
		return os << Frc.n << "/" << Frc.d;
	}
	template <class T, class U>
	Fraction<T> operator *(const Fraction<T>& lhs, const U& rhs)
	{
		Fraction<T> res;
		res.n = lhs.n*rhs;
		res.d = lhs.d;
		return res.reduce();
	}
	template <class T, class U>
	Fraction<T> operator *(const U& lhs, const Fraction<T>& rhs)
	{
		Fraction<T> res;
		res.n = lhs*rhs.n;
		res.d = rhs.d;
		return res.reduce();
	}
	using Frci = Fraction<int>;
	using Frcu = Fraction<unsigned>;
	using Frcs = Fraction<short>;
	using Frcus = Fraction<unsigned short>;
	using Frcll = Fraction<long long>;
}
#endif
