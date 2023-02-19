#include <iostream>

class Fraction
{
private:
	int numerator_;
	int denominator_;

	int comDenominator(int denominator_1, int denominator_2) //определение общего знаменателя
	{
		if (denominator_1 == denominator_2){return denominator_1;}

		int x = 1;
		for (int i = 2; i <= (denominator_1 > denominator_2 ? denominator_1 : denominator_2); ++i)
		{
			if (denominator_1 % i == 0 && denominator_2 % i == 0)
			{
				denominator_1 /= i;
				denominator_2 /= i;
				x *= i;
				--i;
			}
		}
		return denominator_1 * denominator_2 * x;		
	}

public:
	Fraction(int numerator, int denominator)
	{
		numerator_ = numerator;
		denominator_ = denominator;
	}

	bool operator==(const Fraction &other)
	{
		int x = comDenominator(denominator_, other.denominator_);
		return numerator_ * x / denominator_ == other.numerator_ * x / other.denominator_;
	}

	bool operator !=(const Fraction &other)
	{
		return !(*this == other);
	}

	bool operator>(const Fraction &other)
	{
		int x = comDenominator(denominator_, other.denominator_);
		return numerator_ * x / denominator_ > other.numerator_ * x / other.denominator_;
	}

	bool operator<=(const Fraction &other)
	{
		return !(*this > other);
	}

	bool operator<(const Fraction &other)
	{
		int x = comDenominator(denominator_, other.denominator_);
		return numerator_ * x / denominator_ < other.numerator_ * x / other.denominator_;
	}

	bool operator>=(const Fraction &other)
	{
		return !(*this < other);
	}
};

int main()
{
	Fraction f1(4, 3);
	Fraction f2(6, 11);	
	std::cout << "f1" << ((f1 == f2) ? " == " : " not == ") << "f2" << '\n';
	std::cout << "f1" << ((f1 != f2) ? " != " : " not != ") << "f2" << '\n';
	std::cout << "f1" << ((f1 < f2) ? " < " : " not < ") << "f2" << '\n';
	std::cout << "f1" << ((f1 > f2) ? " > " : " not > ") << "f2" << '\n';
	std::cout << "f1" << ((f1 <= f2) ? " <= " : " not <= ") << "f2" << '\n';
	std::cout << "f1" << ((f1 >= f2) ? " >= " : " not >= ") << "f2" << '\n';
	return 0;
}