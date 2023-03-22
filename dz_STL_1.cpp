// dz_STL_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

/*
	1) Создайте вектор для хранения элементов типа Point. Сохраните
	в этом векторе 5 элементов типа Point.
	Выведите элементы сохраненного вектора на экран.
*/
class Point  // класс Point
{
	int x;
	int y;
public:
	Point() : x(0), y(0) {}
	Point(int xP, int yP) : x(xP), y(yP) {}

	// дружественная ф-ия для перегрузки оператора <<
	friend std::ostream& operator<<(std::ostream&, const Point&);
};

std::ostream& operator<<(std::ostream& out, const Point& p)
{
	out << p.x << "." << p.y << '\n';
	return out;
}

int main1()
{
	// создание и инициализация объектов класса Point
	Point obj1(1,2);
	Point obj2(2,3);
	Point obj3(13,1);
	Point obj4(5,7);
	Point obj5(2,4);

	// создание объекта типа вектор
	std::vector<Point>vect;

	// добавление элементов Point в конец массива vect
	vect.push_back(obj1); 
	vect.push_back(obj2);
	vect.push_back(obj3);
	vect.push_back(obj4);
	vect.push_back(obj5);

	// объявление итератора только для чтения
	std::vector<Point>::const_iterator it;
	// цикл от первого до следующего за последним элементом
	for (it = vect.begin(); it != vect.end(); ++it)
	{
		// вывод на экран значения, на которое указывает итератор
		std::cout << *it << ' ';
	}

	return 0;
}


/*	
	2) Создайте ассоциативный массив (контейнер map) из 5 элементов 
	для сохранения информации о среднем балле студентов.
	Каждый элемент этого контейнера будет содержать пару 
	"имя студента" - средний балл студента.
*/

int main()
{
	std::map<std::string, double> _map;  // ассоциативый массив map
	// добавляем элементы (ключ-значение)
	_map.insert(std::make_pair("Fokin", 10.1));
	_map.insert(std::make_pair("Radchenko", 9.8));
	_map.insert(std::make_pair("Abramovich", 7.0));
	_map.insert(std::make_pair("Kornitskiy", 11.5));
	_map.insert(std::make_pair("Ivanov", 11.0));

	std::map<std::string, double>::const_iterator it;  // итератор
	it = _map.begin();  // присваиваем начальное значение итератору
	
	double sum = 0;  // переменная для суммы оценок
	while (it != _map.end())  // цикл до последнего элемента
	{
		// вывод на экран значений пар элементов
		std::cout << it->first << " has " << it->second << '\n';
		sum += it->second;  // суммируем оценки
		++it;
	}
	double av = sum / 5;  // средний балл всей группы
	std::cout << "Average rating is: " << av;
	return 0;
}
