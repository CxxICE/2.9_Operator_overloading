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

	void comDivision(Fraction &f) //определение наибольшего общего делителя и сокращение дроби
	{
		int x = 1;//НОД
		int numerator = f.numerator_;
		int denominator = f.denominator_;
		if (numerator < 0) { numerator = -numerator; }
		for (int i = 2; i <= (numerator < denominator ? denominator : numerator); ++i)
		{
			if (numerator % i == 0 && denominator % i == 0)
			{
				numerator /= i;
				denominator /= i;
				x *= i;
				--i;
			}
		}
		f.numerator_ /= x;
		f.denominator_ /= x;		
	}

public:
	Fraction() {};
	Fraction(int numerator, int denominator)
	{
		numerator_ = numerator;
		denominator_ = denominator;
	}
	void inputNumerator()
	{
		std::cin >> numerator_;
	}
	void inputDenominator()
	{
		bool err = 0;
		do
		{
			if (err) { std::cout << "Знаменатель не может быть меньше или равен нулю! Повторите ввод.\n"; }
			std::cin >> denominator_;
			denominator_ <= 0 ? err = 1 : err = 0;
		} while (err == 1);		
	}	

	int getNumerator()
	{
		return numerator_;
	}

	int getDenominator()
	{
		return denominator_;
	}

	Fraction operator+(const Fraction &other)
	{
		Fraction temp;
		int x = comDenominator(denominator_, other.denominator_);
		temp.numerator_ = (numerator_ * x / denominator_ + other.numerator_ * x / other.denominator_);
		temp.denominator_ = x;		
		comDivision(temp);
		return temp;
	}

	Fraction operator-(const Fraction &other)
	{
		Fraction temp;
		int x = comDenominator(denominator_, other.denominator_);
		temp.numerator_ = (numerator_ * x / denominator_ - other.numerator_ * x / other.denominator_);
		temp.denominator_ = x;		
		comDivision(temp);		
		return temp;
	}

	Fraction operator*(const Fraction &other)
	{
		Fraction temp;
		temp.numerator_ = numerator_ * other.numerator_;
		temp.denominator_ = denominator_ * other.denominator_;
		comDivision(temp);
		return temp;
	}

	Fraction operator/(const Fraction &other)
	{
		Fraction temp;
		temp.numerator_ = numerator_ * other.denominator_;
		temp.denominator_ = denominator_ * other.numerator_;
		comDivision(temp);
		return temp;
	}

	Fraction operator-()
	{
		return Fraction(-numerator_,denominator_);
	}

	Fraction& operator++()
	{
		numerator_ += denominator_;
		comDivision(*this);
		return *this;
	}

	Fraction operator++(int)
	{
		Fraction temp = *this;
		numerator_ += denominator_;
		comDivision(*this);
		return temp;
	}

	Fraction& operator--()
	{
		numerator_ -= denominator_;
		comDivision(*this);
		return *this;
	}

	Fraction operator--(int)
	{
		Fraction temp = *this;
		numerator_ -= denominator_;
		comDivision(*this);
		return temp;
	}
};

int main()
{
	setlocale(LC_ALL, "RU");
	
	Fraction f1;
	Fraction f2;
	Fraction f3;

	std::cout << "Введите числитель дроби 1: ";
	f1.inputNumerator();
	std::cout << "Введите знаменатель дроби 1: ";
	f1.inputDenominator();
	std::cout << "Введите числитель дроби 2: ";
	f2.inputNumerator();
	std::cout << "Введите знаменатель дроби 2: ";
	f2.inputDenominator();

	std::cout	<< f1.getNumerator() << "/" << f1.getDenominator() << " + " 
				<< f2.getNumerator() << "/" << f2.getDenominator() << " = "
				<< (f1 + f2).getNumerator() << "/" << (f1 + f2).getDenominator() << std::endl;

	std::cout	<< f1.getNumerator() << "/" << f1.getDenominator() << " - " 
				<< f2.getNumerator() << "/" << f2.getDenominator() << " = "
				<< (f1 - f2).getNumerator() << "/" << (f1 - f2).getDenominator() << std::endl;

	std::cout	<< f1.getNumerator() << "/" << f1.getDenominator() << " * " 
				<< f2.getNumerator() << "/" << f2.getDenominator() << " = "
				<< (f1 * f2).getNumerator() << "/" << (f1 * f2).getDenominator() << std::endl;

	std::cout	<< f1.getNumerator() << "/" << f1.getDenominator() << " / " 
				<< f2.getNumerator() << "/" << f2.getDenominator() << " = "
				<< (f1 / f2).getNumerator() << "/" << (f1 / f2).getDenominator() << std::endl;
	
	std::cout	<< "-" << f1.getNumerator() << "/" << f1.getDenominator() << " = "
				<< (-f1).getNumerator() << "/" << (-f1).getDenominator() << std::endl;
	
	std::cout	<< "++" << f1.getNumerator() << "/" << f1.getDenominator() << " * "
				<< f2.getNumerator() << "/" << f2.getDenominator() << " = ";
	f3 = ++f1 * f2;
	std::cout	<< f3.getNumerator() << "/" << f3.getDenominator() << std::endl;
	std::cout	<< "Значение дроби 1 = " << f1.getNumerator() << "/" << f1.getDenominator() << std::endl;	

	std::cout	<< f1.getNumerator() << "/" << f1.getDenominator() << "-- * "
				<< f2.getNumerator() << "/" << f2.getDenominator() << " = ";
	f3 = f1-- * f2;
	std::cout	<< f3.getNumerator() << "/" << f3.getDenominator() << std::endl;
	std::cout	<< "Значение дроби 1 = " << f1.getNumerator() << "/" << f1.getDenominator() << std::endl;

	std::cout	<< "--" << f1.getNumerator() << "/" << f1.getDenominator() << " * "
		<< f2.getNumerator() << "/" << f2.getDenominator() << " = ";
	f3 = --f1 * f2;
	std::cout	<< f3.getNumerator() << "/" << f3.getDenominator() << std::endl;
	std::cout	<< "Значение дроби 1 = " << f1.getNumerator() << "/" << f1.getDenominator() << std::endl;	

	std::cout	<< f1.getNumerator() << "/" << f1.getDenominator() << "++ * "
		<< f2.getNumerator() << "/" << f2.getDenominator() << " = ";
	f3 = f1++ * f2;
	std::cout	<< f3.getNumerator() << "/" << f3.getDenominator() << std::endl;
	std::cout	<< "Значение дроби 1 = " << f1.getNumerator() << "/" << f1.getDenominator() << std::endl;

	return 0;
}