#pragma once
#include <string>
#include <iostream>

class Exception {
public:
	std::string error_name;
	std::string file_name;
	std::string function;
	std::string date;
	size_t line;
	std::string time;
	Exception(const std::string& file_name, const std::string& function, size_t line, const std::string& error_name) {
		this->file_name = file_name;
		this->function = function;
		this->line = line;
		this->error_name = error_name;
		this->time = __TIME__;
		this->date = __DATE__;
	}
};
std::ostream& operator<<(std::ostream& out, const Exception& exception) {
	out << "Error name: " << exception.error_name << std::endl <<
		"File: " << exception.file_name << std::endl <<
		"Function: " << exception.function << std::endl <<
		"Line: " << exception.line << std::endl <<
		"Date: " << exception.date << std::endl <<
		"Time: " << exception.time << std::endl;
	return out;
}