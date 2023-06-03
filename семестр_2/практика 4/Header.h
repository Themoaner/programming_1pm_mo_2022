#pragma once
#include <iostream>
#include <sstream>

class Devices
{
public:
	virtual void poll()
	{
		std::cout << "Device name";
	}
};

class electrical_energy_meter : public Devices
{
public:
	void poll() override
	{
		std::cout << "Electrical Energy Meter" << std::endl;
	}
};

class discrete_signals : public Devices
{
public:
	void poll() override
	{
		std::cout << "Discrete Signals" << std::endl;
	}
};

class heating_bloks : public Devices
{
public:
	void poll() override
	{
		std::cout << "heating bloks" << std::endl;
	}

};
