#include "Keylog.hh"

Keylog::Keylog() : type_(Keylog::Type::NONE)
{
}

Keylog::Keylog(Type type, unsigned char key) : type_(type), key_(key)
{
}

Keylog::Keylog(Type type, unsigned char key, long x, long y) : type_(type), key_(key), x_(x), y_(y)
{
}

Keylog::~Keylog()
{
}
