#ifndef SDDS_EVENT_H
#define SDDS_EVENT_H

extern unsigned int g_sysClock;

namespace sdds {	
	
	class Event {

		char *desc;
		unsigned int startTime;

	public:
		Event();
		~Event();
		Event(const Event& copy);
		Event& operator=(const Event& assi);
		void display();
		void setDescription(char* descri);
	};
}

#endif