#include<iostream>
#include"Time.hpp"

using namespace std;

int main(){

	Time morning = Time(7, 30, 00);
	Time morning2 = Time(7, 30, 00);


	Time evening = Time(8, 20, 00);

	if (morning == morning2) {
		cout << "Times are the same" << endl;
	}
	else
	{
		cout << "Times NOT are the same" << endl;
	}

	morning + 20000;
	morning + morning2;
	morning.add(20);

	Time timeToAdd = Time(5, 33, 20);
	morning2.add(timeToAdd);

	morning.display();
	morning2.display();

	//morning + morning2;



	system("pause");
	return 0;
}