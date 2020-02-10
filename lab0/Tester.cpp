#include<iostream>
#include"EvenNumber.h"
#include"EvenNumber.h"
using namespace sdds;
using namespace std;
int main() {
	int num;
	cout << "Enter any even number: ";
	cin >> num;
	EvenNumber t(num);
	while(t.getValue()==-1) 
	{
		cout << "You entered a wrong value, please try again: ";
		cin >> num;
		t = num;
	}
	cout << "Entered number is: " << t.getValue() << endl;
	cout << "Next Nmuber is: " << t.getNext().getValue() << endl;
	cout << "Previous Nmuber is: " << t.getPrevious().getValue() << endl;
	return 0;
}
