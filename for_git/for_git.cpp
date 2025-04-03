//#include <iostream>
//
//class Gun //базовый класс
//{
//public:
//    virtual void Shoot() {
//        std::cout << "Bang\n";
//    }
//};
//
//class Submashinegun:public Gun { //производный класс
//public:
//    void Shoot() override //override для проверки компилятором сигнатуры** метода
//    //** Сигнатура метода в программировании — это его имя и информация о параметрах.Тип возвращаемого значения исключён из сигнатуры.
//    { //переопределённый метод
//        std::cout << "BANG\n" << "BANG\n" << "BANG\n";
//    }
//};
//
//class Granatomet :public Gun {
//public:
//    void Shoot() override {
//        std::cout << "WE COUGHT THE TERRORIST!!!\n";
//    }
//};
//
//class Player {
//public:
//    void Shoot(Gun *gun) {
//        gun->Shoot(); //gun здесь будет адаптироваться под что угодно, зависит от передаваемого аргумента
//        //итого:
//       /* *в main создаём объект класса нужного нам огнестрела
//        *передаём ссылку на нужный тип в функцию класса Player 
//        *делаем выстрел*/
//    }
//};
//
//
//
//int main()
//{
//    Submashinegun makarov;
//    Granatomet bazooka;
//    //Submashinegun makarov;
//    Player terminator;
//    terminator.Shoot(&makarov);
//    //Gun* weapon = &kolt45;
//    Player terrorist;
//    terrorist.Shoot(&bazooka);
//
//    //weapon->Shoot(); //вызов метода от указателя
//
//    //создаём объект дочернего класса
//    //в скобках у метода Shoot ссылаемся на созданный объект нужного класса
//}

#include<iostream>
#include<string>
#include<vector>

class Expedition {
public:
	virtual void info() {
		std::cout << ""
	}
};

cl

class Explorer {
public:
	std::vector<std::string> Items; //арсенал
	int Dollars; //количество денег
};
	
class Arswnal {
public:
	std::string item;
};
