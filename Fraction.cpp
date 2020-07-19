//http://window.edu.ru/catalog/pdf2txt/950/79950/60322?p_page=14
/*
Реализуйте класс Дробь.
Необходимо хранить числитель и знаменатель в качестве переменных-членов.
Реализуйте функции-члены для ввода данных в переменные-члены, для выполнения арифметических операций
(сложение, вычитание, умножение, деление, и т.д.).
(addition, subtraction, multiplication, division)
*/
//http://window.edu.ru/catalog/pdf2txt/950/79950/60322?p_page=13
#include <iostream>
using namespace std;
class Fraction
{
private:
	int sign;           // знак дроби (+ или -)
	int intPart;        // целая часть дроби
	int numerator;      // числитель дроби
	int denominator;    // знаменатель дроби
	//преобразование в смешанный вид
	void GetMixedView();
	void Cancellation();  //сокращение дроби
	void GetIntPart();    //выделение целой части дроби
public:
	Fraction(); // конструктор без параметров
		  //конструктор c параметрами
	Fraction(int, int, int = 0, int = 1);
	//деструктор
	~Fraction();
	// метод сложения двух дробей
	Fraction operator + (Fraction);
	// метод сложения дроби с целым числом
	Fraction operator + (int);
	// метод вычитания двух дробей
	Fraction operator - (Fraction);
	// метод вычитания из дроби целого числа
	Fraction operator - (int);
	// метод умножения двух дробей
	Fraction operator * (Fraction);
	// метод умножения дроби на целыое число
	Fraction operator * (int);
	// метод деления двух дробей
	Fraction operator / (Fraction);
	// метод деления дроби на целое число
	Fraction operator / (int);
	// метод умножения на (-1)
	Fraction operator - ();
	// дружественные функции
	//// функция сложения целого числа и дроби
	//friend Fraction operator + (int, Fraction);
	//// функция вычитания дроби из целого числа
	//friend Fraction operator - (int, Fraction);
	//// функция умножения целого числа и дроби
	//friend Fraction operator * (int, Fraction);
	//// функция деления целого числа на дробь
	//friend Fraction operator / (int, Fraction);
	//// метод преобразования в тип double
	//operator double();
	// методы сравнения двух дробей
	//bool operator > (Fraction);
	//bool operator < (Fraction);
	//bool operator >= (Fraction);
	//bool operator <= (Fraction);
	//bool operator != (Fraction);
	//bool operator == (Fraction);
	//функция ввода дроби
	//friend istream& operator >> (istream&, Fraction&);
	////функция вывода дроби
	//friend ostream& operator << (ostream&, Fraction&);



	void Print();

};
////конструктор c параметрами
//Fraction(int, int, int = 0, int = 1);
// конструктор класса "Рациональная дробь"
Fraction::Fraction(int n, int d, int i, int s) {
	intPart = i;
	numerator = n;
	denominator = d;
	sign = s;
	GetMixedView();
}
// конструктор по умолчанию класса "Рациональная дробь"
Fraction::Fraction() {
	intPart = 0;
	numerator = 0;
	denominator = 1;
	sign = 1;
}
// метод преобразования дроби в смешанный вид
void Fraction::GetMixedView() {
	GetIntPart(); //выделение целой части числа
	Cancellation();     //сокращение дроби
}
// метод выделения целой части рационального числа
void Fraction::GetIntPart() {
	if (numerator >= denominator) {
		intPart += (numerator / denominator);
		numerator %= denominator;
	}
}
// метод сокращения рациональной дроби
void Fraction::Cancellation() {
	if (numerator != 0) {
		int m = denominator,
			n = numerator,
			ost = m % n;
		// вычисление НОД(числитель, знаменатель)
		// алгоритмом Евклида
		while (ost != 0) {
			m = n; n = ost;
			ost = m % n;
		}
		int nod = n;
		if (nod != 1) {
			numerator /= nod; denominator /= nod;
		}
	}
}
// деструктор дроби
Fraction::~Fraction() {
	cout << "Дробь " << this << " уничтожена." << endl;
}
// операция преобразования дроби в тип double
//Fraction::operator double() {
//	double res = (double)sign * (intPart * denominator + numerator) / denominator;
//	return res;
//}
// операции сравнения двух дробей
/*
bool Fraction::operator ==(Fraction a) {
	if (sign != a.sign || intPart != a.intPart || numerator * a.denominator != denominator * a.numerator)
		return false;
	return true;
}
bool Fraction::operator !=(Fraction a) {
	if (sign == a.sign && intPart == a.intPart && numerator * a.denominator == denominator * a.numerator)
		return false;
	return true;
}
bool Fraction::operator > (Fraction a) {
	if (double(*this) <= double(a))
		return false;
	return true;
}

bool Fraction::operator < (Fraction a) {
	if (double(*this) >= double(a))
		return false;
	return true;
}
bool Fraction::operator >= (Fraction a) {
	if (double(*this) < double(a))
		return false;
	return true;
}
bool Fraction::operator <= (Fraction a) {
	if (double(*this) > double(a))
		return false;
	return true;
}
*/
// операция сложения двух дробей
Fraction Fraction::operator + (Fraction a) {
	Fraction res;
	res.numerator = sign * (intPart * denominator + numerator) * a.denominator + a.sign * (a.intPart * a.denominator + a.numerator) * denominator;
	res.denominator = denominator * a.denominator;
	if (res.numerator < 0) {
		res.numerator *= -1; res.sign = -1;
	}
	res.GetMixedView();
	return res;
}
//// операция сложения дроби и целого числа
//Fraction Fraction::operator + (int a) {
//	Fraction res;
//	Fraction b(0, 1, abs(a), a / abs(a));    // b = a
//	res = (*this) + b; //сложение двух дробей
//	return res;
//}
// определение дружественной функции сложения
// целого числа и дроби
//Fraction operator + (int a, Fraction c) {
//	Fraction res;
//	Fraction b(0, 1, abs(a), a / abs(a));     // b = a
//	res = b + c;        //сложение двух дробей
//	return res;
//}
// операция печати дроби
//ostream& operator << (ostream& out, Fraction& a) {
//	// знак числа печатается только
//	// если число отрицательно
//	if (a.sign < 0)
//		out << "-";
//	// если целая часть не равна 0, выводим ее
//	if (a.intPart != 0)
//		out << a.intPart << " ";
//	// дробная часть печатается, если числитель не равен
//	if (a.numerator != 0)
//		out << a.numerator << "/" << a.denominator;
//	// если и целая часть и дробная часть равны 0,
//	// то число равно 0
//	if (a.intPart == 0 && a.numerator == 0)
//		out << "0";
//	// если вывод осуществляется в файл,
//	// используется символ '\t'
//	if (typeid(ofstream) == typeid(out))
//		out << "\t";
//	else out << " ";
//	return out;
//}
// операция ввода рациональной дроби
//istream& operator >>(istream& fin, Fraction& a) {
//	char buf[30];
//	// считывается число в строку
//	// если считывание происходит из файла,
//	// строка вводится до разделителя
//	if (typeid(ifstream) == typeid(fin))
//		fin.getline(buf, 29, '\t');
//	else
//		fin.getline(buf, 29);
//	// находим первое вхождение символа '/' в строку
//	char* ps = strchr(buf, '/');
//	// если символ не найден,
//	// т.е. число - без дробной части
//	if (ps == NULL) {
//		// из строки выделяем целую часть
//		sscanf(buf, "%d", &a.intPart);
//		a.numerator = 0;
//		a.denominator = 1;
//		//знак числа определяется по знаку целой части
//		if (a.intPart >= 0)
//			a.sign = 1;
//		else {
//			a.sign = -1;
//			a.intPart = -a.intPart;
//		}
//		return fin;
//	}
//	// если число без целой части
//	if (strchr(buf, ' ') == NULL) {
//		a.intPart = 0;
//		// считываем из строки числитель и знаменатель
//		sscanf(buf, "%d/%d",
//			&a.numerator, &a.denominator);
//		//знак числа определяется по знаку числителя
//
//		if (a.numerator > 0)
//			a.sign = 1;
//		else {
//			a.sign = -1;
//			a.numerator = -a.numerator;
//		}
//		a.GetMixedView();
//		return fin;
//	}
//	// считывание всех составляющих дроби
//	// и определение знака
//	sscanf(buf, "%d %d/%d", &a.intPart, &a.numerator, &a.denominator);
//	if (a.intPart > 0)
//		a.sign = 1;
//	else {
//		a.sign = -1;
//		a.intPart = -a.intPart;
//	}
//	a.GetMixedView();
//	return fin;
//}
//int main() {
//	
//	Fraction d1(2, 3, 0, 1);   // создание дроби 2/3
//	Fraction d2(4, 5, 2, -1); // создание дроби -2 4/5
//	Fraction d3(4, 3, 1, 1); // создание дроби 2 1/3
//	Fraction d4(10, 6);       // создание дроби 1 2/3
//	Fraction d5(3, 7);        // создание дроби 3/7
//	Fraction d6(3, 8, 2);     // создание дроби 2 3/8
//	Fraction d7;         // создание рационального числа 0
//	cout << "***************************************************************" << endl;
//	Fraction r1(2, 3, 0, 1);
//	cout << "r1 = " << r1;
//	Fraction r2(5, 7, 0, 1);
//	cout << "r2 = " << r2;
//	cout << "-r2= " << (r2);
//	//cout << "r2 = " << (double)r2;
//	cout << endl;
//	Fraction d;
//	// вызов оператора "==" для двух дробей
//	if (r1 == r2)
//		cout << "r1 == r2" << endl;
//	else
//		cout << "r1 != r2" << endl;
//	// вызов оператора ">" для двух дробей
//	if (r1 > r2)
//		cout << "r1 > r2" << endl;
//	else
//		cout << "r1 <= r2" << endl;
//	// вызов оператора "+" для двух дробей
//	d = r1 + r2;
//	cout << "r1+r2=" << d;
//	// вызов оператора "+" для дроби и числа
//	d = r1 + (-11);
//	cout << "r1+(-11)=" << d;
//	// вызов оператора "*" для числа и дроби
//	d = 5 + r1;
//	cout << "5 + r1 = " << d;
//	// вызов оператора преобразования дроби к типу double
//	/*Fraction q(1, 3);
//	double f = q;*/
//}
void Fraction::Print() {
	//GetMixedView();
	cout << "sign = " << sign << endl << intPart << ' ' << numerator << "/" << denominator << endl;
}
int main() {
	Fraction a(1, 5, 7, -1);
	Fraction b(3, 2, 5, -1);
	Fraction c = a + b;
	Fraction c1 = a + b;
	c1.Print();







	//fraction d1(2, 3, 0, 1);   // создание дроби 2/3
	//fraction d2(4, 5, 2, -1); // создание дроби -2 4/5
	//fraction d3(4, 3, 1, 1); // создание дроби 2 1/3
	//fraction d4(10, 6);       // создание дроби 1 2/3
	//fraction d5(3, 7);        // создание дроби 3/7
	//fraction d6(3, 8, 2);     // создание дроби 2 3/8
	//fraction d7;         // создание рационального числа 0
}





















/*
#include <iostream>
using namespace std;
class Fraction
{
public:
	//void SetWhole();
	//int GetWhole();
	void SetNumerator();
	void SetNumerator2();
	int GetNumerator();
	int GetNumerator2();
	void SetDenominator();
	void SetDenominator2();
	int GetDenominator();
	int GetDenominator2();

	int Addition(int a, int b, int c, int d); //сложение
	//int AdditionNumerator(); //сложение Numerator
	//int AdditionDenominator(); //сложение Denominator
	int Subtraction(); //вычитание
	int Multiplication(); //умножение
	int Division(); //деление

	void Print();
private:
	//int Whole = 0; //целая часть
	int Numerator = 0; //числитель
	int Numerator2 = 0; //числитель
	int Denominator = 0; //знаменатель
	int Denominator2 = 0; //знаменатель
};

//void Fraction::SetWhole() {
//	cout << "Enter the Whole : ";
//	cin >> Whole;
//}

//int Fraction::GetWhole() {
//	return 0;
//}

void Fraction::SetNumerator() {
	cout << "Enter the Numerator : ";
	cin >> Numerator;
}

void Fraction::SetNumerator2() {
	cout << "Enter the Numerator2 : ";
	cin >> Numerator2;
}

int Fraction::GetNumerator() {
	return Numerator;
}

int Fraction::GetNumerator2() {
	return Numerator2;
}

void Fraction::SetDenominator() {
	cout << "Enter the Denominator : ";
	cin >> Denominator;
}

void Fraction::SetDenominator2() {
	cout << "Enter the Denominator2 : ";
	cin >> Denominator2;
}

int Fraction::GetDenominator() {
	return Denominator;
}

int Fraction::GetDenominator2() {
	return Denominator2;
}

int Fraction::Addition(int a, int a2, int b, int b2) {
	/*
	a   c	a+c
	- + - = ---
	b	b	 b

	if (b == b2) {
		int rezA = a + a2;
		int rezB = b;
	}
	if(b != b2)





		int RezNumerator = GetNumerator() + GetNumerator2();

	return RezNumerator;
}
//int Fraction::AdditionDenominator() {
//	int RezDenominator = GetDenominator() + GetDenominator2();
//	return RezDenominator;
//}


int Fraction::Subtraction() {
	return 0.0;
}

int Fraction::Multiplication() {
	return 0.0;
}

int Fraction::Division() {
	return 0.0;
}

void Fraction::Print() {
	cout << "Numerator : " << Fraction::Numerator << endl;
	cout << "Denominator : " << Fraction::Denominator << endl;
}


int main() {
	Fraction a;
	a.SetNumerator();
	a.SetNumerator2();
	a.SetDenominator();
	a.SetDenominator2();
	//cout "сложение = " << a.AdditionNumerator() << '/' << a.AdditionDenominator();


}
*/