#include <iostream>
#include "TList.h"
#include "TPolinom.h"
#include "TMonom.h"
#include<vector>
int f = 0;
int count_oper(std::string s) {
	int count = 0;

	for (int i = 0; i < s.size(); i++)
		if (s[i] == '+' || s[i] == '-' || s[i] == '*') count++;

	return count;
}
TPolinom Polinomoperation(std::string& operation, std::vector<TPolinom>& polyVector)
{
	size_t pos = operation.find_first_of("+-*"); // ���� ������� ������ �� �������� "+", "-", "*", "="
	int count = count_oper(operation);
	if (count > 1)
	{
		f = 1;
		return TPolinom();
	}
	if (pos != std::string::npos && pos > 0 && pos < operation.size() - 1)
	{
		char operationChar = operation[pos]; // �������� ������ ��������
		int index1;
		int index2;
		if (operation[pos + 1] == '=')
		{
			operationChar = '=';
			pos++;
			index1 = std::stoi(operation.substr(0, pos - 2)) - 1;
			index2 = std::stoi(operation.substr(pos + 1, operation.size())) - 1;
		}
		else
		{
			if (operation[pos + 1] == '(')
			{
				operationChar = '(';
				pos++;

				index1 = std::stoi(operation.substr(0, pos - 2)) - 1;
				index2 = std::stoi(operation.substr(pos + 1, operation.size() - 1));
			}
			else
			{
				index1 = std::stoi(operation.substr(0, pos - 1)) - 1;
				index2 = std::stoi(operation.substr(pos + 1, operation.size())) - 1;
			}

		}

		TPolinom result;
		// ��������� ������� �� ������ ��������

		if (index1 >= 0 && index1 < polyVector.size() && index2 >= 0 && index2 < polyVector.size())
		{

			switch (operationChar)
			{

			case '+':
				//result = P1 + P2;
				f = 0;
				return polyVector[index1] + polyVector[index2];
			case '-':
				f = 0;
				//result = P1 - P2;
				return polyVector[index1] - polyVector[index2];
			case '*':
				f = 0;
				//result = P1 * P2;
				return polyVector[index1] * polyVector[index2];
			case '=':
				f = 0;
				//result = P1 += P2;
				return polyVector[index1] += polyVector[index2];
			case '(':
				f = 0;
				return polyVector[index1] * index2;
			default:
				f = 1;
			}
		}
		else
		{
			f = 1;
		}
	}
	else
	{
		f = 1;
	}

	return TPolinom(); // ���������� ������ �������, ���� �������� �� ��������� �������
}
int main()
{
	std::string a = "2x^1y^1z^1 + 3x^2y^3z^1 + 1x^1y^1z^0";
	std::string b = "5x^2y^1z^1";
	std::string ab = " 1 *(1)";
	TPolinom p1(a),p2(b);
	std::vector<TPolinom> V;
	V.push_back(p1);
	V.push_back(p2);
	V.push_back(p2);
	TPolinom res=Polinomoperation(ab, V);
	std::cout<<res<<std::endl;
	std::cout<<V.size();

}
