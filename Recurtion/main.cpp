//Recurtion
#include<iostream>
using namespace std;
void elevator(int level)
{
	if (level == 0)return;
	cout << level << endl;
	elevator(level - 1);//–екурсивный вызов
	//cout << level << endl;
}
double power(double a, int n)
{
	if (n == 0)return 1;
	double num = a * power(a, n - 1);
	return num;
	if (n < 0)
	{
		num = 1 / a * power(a, n + 1);
	}
}
int factorial(int a)
{
	if (a == 0)return 1;
	return a * factorial(a - 1);
}
void main()
{
	setlocale(LC_ALL, "ru");
	//cout << "Hello World";
	//main();//–екурсивный вызов функции main
#ifdef ELEVATOR
	int n;
	cout << "¬ведите номер этажа: "; cin >> n;
	elevator(n);
#endif // ELEVATOR
#ifdef POWER
	double a, num;
	int n;
	cout << "¬ведите основание степени: "; cin >> a;
	cout << "¬ведите значение степени: "; cin >> n;
	cout << "ќтвет: " << power(a, n);
#endif // POWER
	int a;
	cout << "¬ведите число: "; cin >> a;
	cout << "‘акториал данного числа: " << factorial(a);

	
}