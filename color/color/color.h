/*
	https://github.com/steak137
	dev: watan beck
*/

#ifndef __COLOR_H__
#include <fstream>
#include <string>
#if COMPILER_VER >= 202002L
#include <format.h>
#endif

class color {
public:
	color(int r, int g, int b) : r_(r), g_(g), b_(b) {}
	friend std::ostream& operator<<(std::ostream& os, const color& color) {
#if COMPILER_VER >= 202002L
		return os << std::format("\x1B[38;2;{};{};{}m", color.r_, color.g_, color.b_);
#else
		std::stringstream fmt;
		fmt << "\x1B[38;2;" << color.r_ << ";" << color.g_ << ";" << color.b_ <<"m";
		return os << fmt.str();
#endif
	}
	~color() {}
	friend std::ostream& operator<<(std::ostream& os) {
#if COMPILER_VER >= 202002L
		return os << std::format("\x1B[38;2;255;255;255m");
#else
		std::stringstream fmt;
		fmt << "\x1B[38;2;255;255;255m";
		return os << fmt.str();
#endif
	}
private:
	int r_, g_, b_;
};

#endif __COLOR_H__
