//В системе «Умный дом» используется управляющий компьютер, который взаимодействует с различными приборами.
//Приборы подразделяются на несколько категорий :
//1.	Счетчики электрической энергии
//      a.Меркурий 230
//      b.Нева МТ314
//      c.Энергомера CE308
//2.	Блоки ввода дискретных сигналов :
//      a.Reallab NL - 16HV
//      b.Приборэлектро PRE - 16
//      c.Энергосервис ЭНМВ - 1 - 24
//3.	Блоки управления отоплением
//      a.Ouman S203
//      b.Овен ТРМ232
//
//Получить данные от каждого прибора можно через метод
//
//void poll() {
//	std::cout << “Device name” << std::endl;
//	// Некоторая реализация получения данных, которую вам делать
//	// не нужно.
//}

#include <iostream>
#include <sstream>
#include <fstream>
#include "Header.h"
#include <vector>

int main()
{
	setlocale(LC_ALL, "ru");
	std::vector <Devices*> devices;
	std::string line;

	std::ifstream tt("t.txt");
	if (tt.is_open())
	{
		while (std::getline(tt, line))
		{
			std::cout << line << std::endl;

			if (line == "Меркурий 230" || line == "Нева МТ314" || line == "Энергомера CE308")
			{
				electrical_energy_meter* a = new electrical_energy_meter;
				devices.push_back(a);
			}

			if (line == "Reallab NL-16HV" || line == "Приборэлектро PRE-16" || line == "Энергосервис ЭНМВ-1-24")
			{
				discrete_signals* a = new discrete_signals;
				devices.push_back(a);
			}

			if (line == "Ouman S203" || line == "Ouman S203")
			{
				heating_bloks* a = new heating_bloks;
				devices.push_back(a);
			}
		}
	}
	tt.close();

	for (int i = 0; i < devices.size(); i++)
	{
		devices[i]->poll();
	}

	system("pause");
}
