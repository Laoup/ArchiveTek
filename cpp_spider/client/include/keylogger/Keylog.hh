#ifndef KEYLOG_HH_
# define KEYLOG_HH_

class				Keylog
{
public:

	enum			Type
	{
		KEYBOARD,
		MOUSE,
		NONE
	};

	Keylog();
	Keylog(Type type, unsigned char key);
	Keylog(Type type, unsigned char key, long x, long y);
	~Keylog();

	//GETTERS
	Type			getType() const
	{
		return		type_;
	};

	unsigned char	getKey() const
	{
		return		key_;
	};

	long			getX() const
	{
		return		x_;
	};

	long			getY() const
	{
		return		y_;
	};

private:
	Type			type_;
	unsigned char	key_;

	//MOUSE
	long			x_;
	long			y_;

};

#endif // !KEYLOG_HH_
