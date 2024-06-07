#pragma once
#include <iostream>
#include <string> 
class TMonom
{
public:
	double Coef;
	int index;
	TMonom(double _coef, int _index)
	{
		Coef = _coef;
		index = _index;
	}
	TMonom()
	{
		Coef = 0;
		index = 0;
	}
	TMonom(const TMonom& m)
	{
		Coef = m.Coef;
		index = m.index;
	}
	int Get_index()
	{
		return index;
	}

	// �������� ��������� ==
	bool operator==(const TMonom& other) const {
		return (index == other.index);
	}
	// �������� ��������� !=
	bool operator!=(const TMonom& other) const {
		return !(*this == other);
	}
	// �������� ��������� <
	bool operator<(const TMonom& other) const {
		if (index < other.index)
		{
			return true;
		}
		else
		{
				return false;
		}
	}
	// �������� ��������� >
	bool operator>(const TMonom& other) const {
		if (index > other.index)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	// �������� �����
	friend std::istream& operator>>(std::istream& cin, TMonom& monom) {
		cin >> monom.Coef >> monom.index;
		return cin;
	}
	std::string Monom_to_String()
	{
		std::string res;
		int degx = index / 100;
		int degy = (index / 10) % 10;
		int degz = index % 10;
		std::string coef = std::to_string(Coef);
		res += coef;
		res += "x^" + std::to_string(degx);
		res += "y^" + std::to_string(degy);
		res += "z^" + std::to_string(degz);
		res += " ";
		return res;
	}

	// �������� ������
	friend std::ostream& operator<<(std::ostream& cout, const TMonom& monom) {
		int degx = monom.index / 100;
		int degy = (monom.index / 10)%10;
		int degz = monom.index % 10;
		cout << monom.Coef << "x^" << degx << "y^" << degy << "z^" << degz << " ";
		return cout;
	}
};

