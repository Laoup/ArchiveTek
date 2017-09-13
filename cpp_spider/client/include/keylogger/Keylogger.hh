#ifndef KEYLOGGER_HH_
# define KEYLOGGER_HH_

# include <iostream>
# include <string>
# include <windows.h>
# include "Keylog.hh"

class 			Keylogger
{

public:
	Keylogger();
	~Keylogger();

	Keylog		getKeyPressed();

private:

};

#endif
