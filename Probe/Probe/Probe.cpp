/*
		 int 4
   short int 2
	long int 4
	   float 4
	  double 8
 long double 8
		char 1
		bool 1
*/

/*
#include <iostream>
#include <iomanip>;

using namespace std;

int main()
{
	// int, short int, long int, float, double, long double, char и bool
	cout << setw(12) << "int" << " " << sizeof(int) << endl;
	cout << setw(12) << "short int" << " " << sizeof(short int) << endl;
	cout << setw(12) << setw(12)<< "long int" << " " << sizeof(long int) << endl;
	cout << setw(12) << "float" << " " << sizeof(float) << endl;
	cout << setw(12) << "double" << " " << sizeof(double) << endl;
	cout << setw(12) << "long double" << " " << sizeof(long double) << endl;
	cout << setw(12) << "char" << " " << sizeof(char) << endl;
	cout << setw(12) << "bool" << " " << sizeof(bool) << endl;
	return 0;
}
*/


#include <iostream>

using namespace std;

int main()
{
	
	union
	{
		int value;
		float number = -9.625;
	};
	unsigned int bytes_amount = 4;  // Количество байт
	unsigned int order = bytes_amount * 8; // Количество разрядов
	unsigned int mask = 1 << order - 1; // Маска побитового сравнения смещением единственной единицы влево на (order - 1)
	/*
	for (int i = 1; i <= order; i++)
	{
		cout << ((value & mask) ? '1' : '0');  // если сейчас на первой позиции 0, то value & mask = 0 => false
		value <<= 1; // Побитовый сдвиг числа
		// 1) отделяем знак "мантиссы"
		// у вещественных в отличие от целых, чтобы получить число, обратное по сложению, достаточно инвертировать один бит знака			 
		// 2) отделяем экспоненту. От записанного значения надо отнять 127/1023 (семь/десять 1). Диапазон от -127 до 128 / -1023 - 1024
		if (i == 9 || i == 1)
		{
			cout << ' ';
		}
	}
	cout << endl;
	*/

	// теперь то же с double, занимающим не 4, а 8 байт
	union
	{
		int value[2];
		double number[1] = { 4 };
	};
	for (int i = 1; i <= order; i++)
	{
		cout << ((value[0] & mask) ? '1' : '0');  // если сейчас на первой позиции 0, то value & mask = 0 => false
		value[1] <<= 1;
		if (i == 12 || i == 1)
		{
			cout << ' ';
		}
	}
	for (int i = 1; i <= order; i++)
	{
		cout << ((value[1] & mask) ? '1' : '0');  // если сейчас на первой позиции 0, то value & mask = 0 => false
		value[1] <<= 1;
	}
}

/*
Мои измышления - не нашел точного описания.
float 9.5 записывается так: 0 10000010 00110000000000000000000
Экспонента: 130 - 127 = 3. Т.е. наш базис - 8.
В мантиссе записывается уже только "остаток" оставшийся после подбора наибольшего возможного базиса.
Чтобы получить дополнительную 1: надо 8 поделить на 2 3 раза, а чтобы 0.5 - 4 раза.
Поэтому в мантиссе на 3-ей и 4-ой позиции единицы
-9.5 отличается от 9.5 только первым битом: 1 вместо 0
*/