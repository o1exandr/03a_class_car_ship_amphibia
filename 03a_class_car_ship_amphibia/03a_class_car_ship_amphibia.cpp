/*
Завдання 3а.
Визначити необхідну ієрархію класів, використовуючи множинне успадкування. Продумати тип наслідування.
Транспортний  засіб(виробник, максимальна  швидкість)
		|							|
Машина(число дверей)	Корабель(число турбін)
\			/
	Амфібія
Амфібія матиме 2 імені(перше - успадковане від  класу Машина, друге -  від класу  Корабель)

*/

#include "stdafx.h"
#include <iostream> 
#include <string>


using namespace std;

class Transport
{
protected:

	string vendor;
	int speed;

public:

	Transport(string vendor = "unknown", int speed = 0) :vendor(vendor), speed(speed)
	{

	}

	void setVendor(string v)
	{
		vendor = v;
	}

	string getVendor() const
	{
		return vendor;
	}

	void setSpeed(int s)
	{
		speed = s;
	}

	int getSpeed() const
	{
		return speed;
	}

	void print()
	{
		cout << "\nVendor:\t" << getVendor() << "\t\nSpeed:\t" << getSpeed() << " km\n";
	}

};

class Car : public Transport
{
protected:

	int doors;

public:

	Car(string vendor = "unknown", int speed = 0, int doors = 2) :Transport(vendor, speed), doors(doors)
	{
	}

	Car(Transport t, int doors = 2) :Transport(t), doors(doors)
	{
	}

	void setDoors(int d)
	{
		doors = d;
	}

	int getDoors()const
	{
		return doors;
	}

	void setSpeed(int s)
	{
		speed = s;
	}

	int getSpeed() const
	{
		return speed;
	}

	void print()
	{
		Transport::print();
		cout << "Doors:\t" << doors << endl;
	}
};

class Ship : public Transport
{
protected:

	int turbin;

public:

	Ship(string vendor = "unknown", int speed = 0, int turbin = 1) :Transport(vendor, speed), turbin(turbin)
	{

	}

	void setTurbin(int t)
	{
		turbin = t;
	}

	int getTurbin() const
	{
		return turbin;
	}

	void print()
	{
		Transport::print();
		cout << "Turbin:\t" << turbin << endl;
	}
};

class Amphibia : public Car, public Ship
{

public:

	Amphibia(string vendorC = "unknown", int speedC = 0, string vendorS = "unknown", int speedS = 0, int doors = 2, int turbin = 1) :Car(vendorC, speedC, doors), Ship(vendorS, speedS, turbin)
	{
	}

	Amphibia(Car c, Ship s):Car(c), Ship(s)
	{
	}

	void print()
	{
		Car::print();
		Ship::print();
	}
};

int main()
{
	Transport t("Audi", 180);
	cout << "\n\tTransort";
	t.print();

	Car c(t, 3);
	cout << "\n\tCar";
	c.print();

	Ship s("Waterstrider", 47, 4);
	cout << "\n\tShip";
	s.print();

	Amphibia a(c, s);
	cout << "\n\tAmphibia";
	a.print();

	cout << endl;
	system("pause");
	return 0;
}

