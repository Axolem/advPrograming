#pragma once
#ifndef Time_hpp

class Time
{
private:
	int hours;
	int minutes;
	int seconds;
	void updateTime();

public:
	Time(int, int, int);

	void setHour(int);
	void setMinus(int);
	void setSeconds(int);

	int getHours();
	int getMinutes();
	int getSeconds();

	void display();

	void add(int);
	void add(Time&);

	bool operator == (Time&);
	bool operator != (Time&);
	bool operator > (Time&);

	void operator + (Time&);
	void operator + (int);

};
#endif 


