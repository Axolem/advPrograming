#include "Time.hpp"
#include<iomanip>
#include<iostream>

using namespace std;

Time::Time(int hours, int minutes, int seconds) {
	this->hours = hours;
	this->minutes = minutes;
	this->seconds = seconds;
}

void Time::setHour(int hour) {
	this->hours = hour;
}

void Time::setMinus(int minutes) {
	this->minutes = minutes;
}

void Time::setSeconds(int seconds) {
	this->seconds = seconds;
}

void Time::display() {
	cout << setfill('0')
		<< setw(2) << hours << ':'
		<< setw(2) << minutes << ':'
		<< setw(2) << seconds << endl;
}

int Time::getHours() {
	return hours;
};

int Time::getMinutes() {
	return minutes;
};

int Time::getSeconds() {
	return seconds;
};

bool Time::operator == (Time& comapare) {
	if (
		hours == comapare.hours 
		&& minutes == comapare.minutes
		&& seconds == comapare.seconds
		) {
		return true;
	}

	return false;
}

bool Time::operator != (Time& comapare) {
	if (
		hours != comapare.hours 
		&& minutes != comapare.minutes
		&& seconds != comapare.seconds
		) 
	{
		return true;
	}

	return false;
}

bool Time::operator > (Time& comapare) {
	if (
		hours > comapare.hours
		&& minutes > comapare.minutes
		&& seconds > comapare.seconds
		) 
	{
		return true;
	}

	return false;
}

/**
 * Adds seconds to the time
 * @param {int} seconds
 * @return void
 */
void Time::operator + (int seconds) {
	this->seconds += seconds; // 900

	Time::updateTime();
}

/**
 * Adds seconds to the time
 * @param {int} seconds
 * @return void
 */
void Time::add(int seconds) {
	this->seconds += seconds; // 900

	Time::updateTime();
}

void Time::add(Time& add) {
	this->hours += add.getHours();
	this->minutes += add.getMinutes();
	this->seconds += add.getSeconds();

	Time::updateTime();
}

void Time::operator+ (Time& add) {
	this->hours += add.getHours();
	this->minutes += add.getMinutes();
	this->seconds += add.getSeconds();

	Time::updateTime();
}

void Time::updateTime() {
	while (this->seconds >= 60) {
		this->minutes += 1;
		this->seconds -= 60;
	}

	// Minutes > 60 
	while (this->minutes >= 60)
	{
		this->hours += 1;
		this->minutes -= 60;
	}

	// Hours > 24
	while (this->getHours() >= 24)
	{
		//this->hours += 1;
		this->hours -= 24;
	}
}