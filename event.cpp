#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "event.h"

extern unsigned int g_sysClock;
unsigned int g_sysClock = 0;

namespace sdds {
	
	Event::Event(): startTime(0u){
		desc = nullptr;
	}

	Event::~Event() {
		delete[] desc;
	}

	Event::Event(const Event& copy) {
		desc = nullptr;
		*this = copy;
	}

	Event& Event::operator=(const Event& assi) {
		if (this != &assi) {
			delete[] desc;
			setDescription(assi.desc);
				startTime = assi.startTime;
		}
		return *this;
	}

	void Event::display() {
		static int counter = 0;
		unsigned int timer[3];

		timer[1] = startTime / 60;
		timer[2] = startTime % 60;
		timer[0] = timer[1] / 60;
		timer[1] = timer[1] % 60;

		if (desc == nullptr)
			cout << setw(3) <<setfill(' ') << right << 1 + counter++ <<". " << "[ No Event ]" << endl;
		else
			cout << setw(3) << setfill(' ') << 1 + counter++ << ". " << setw(2) << setfill('0') << right << timer[0] << ":" <<
			setw(2) << setfill('0') << right << timer[1] << ":" <<
			setw(2) << setfill('0') << right << timer[2] << " -> " << desc << endl;
	}
	
	void Event::setDescription(char* descri) {
		if (descri != nullptr && descri[0] != '\0') {			
			desc = new char[strlen(descri) + 1];
			strcpy(desc, descri);
			startTime = g_sysClock;
		}
		else
			desc = nullptr;
	}

}