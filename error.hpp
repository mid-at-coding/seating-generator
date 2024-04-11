#ifndef ERROR_H
#define ERROR_H
#include <iostream>

class Logger{
	std::string levelToStr(int sev);
public:
	enum severity{
		DEBUG,
		INFO,
		WARN,
		NONFATAL,
		FATAL,
		NOTAG
	};
	static severity outputThreshold;
	void log(std::string msg, severity sev, int indentation = 0);
};
#endif
