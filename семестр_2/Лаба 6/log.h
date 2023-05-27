#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <sstream>
#include <chrono>

enum class LogLevel
{
	DEBUG,
	RELEASE
};

class Log
{
private:
	static std::ofstream m_out;
	static LogLevel m_logLevel;

public:
	Log()
	{
		std::cout << "Constructor" << std::endl;
	}

	static void SetLogLevel(LogLevel logLevel)
	{
		m_logLevel = logLevel;
	}

	static void SetLogPath(const std::string& path)
	{
		m_out.open(path);
	}

	static void Write(const std::string& msg)
	{
		time_t now = time(0);
		char* dt = ctime(&now);
		if (m_logLevel == LogLevel::DEBUG)
		{
			std::cerr << msg << std::endl;
		}
		m_out << dt << msg << std::endl;
		m_out.flush();
	}

	static void INFO(const std::string& msg)
	{
		//time_t now = time(0);
		//char* dt = ctime(&now);
		if (m_logLevel == LogLevel::DEBUG)
		{
			std::cerr << msg << std::endl;
		}
		m_out << /*dt <<*/ msg << std::endl;
		m_out.flush();
	}

	static void ERROR(const std::string& msg)
	{
		//time_t now = time(0);
		//char* dt = ctime(&now);
		if (m_logLevel == LogLevel::DEBUG)
		{
			std::cerr << msg << std::endl;
		}
		m_out << /*dt <<*/ msg << std::endl;
		m_out.flush();
	}

	~Log()
	{
		std::cout << "Destructor" << std::endl;
	}
};
