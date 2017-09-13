NAME	= arcade
RM		= rm -f
CXX		= g++

CXXFLAGS	+= -fPIC -Wall -Wextra -g3 -I./include -std=c++11 -std=gnu++11

LIBPATH		= src/graphic
GAMEPATH	= src/games
ARCADEPATH	= src/luncher

GRAPHIC	= sdl libcaca
GAMES 	= solarfox snake

SRC		= $(ARCADEPATH)/luncher.cpp \
				$(ARCADEPATH)/event.cpp \
				src/arcade.cpp
OBJ		= $(SRC:.cpp=.o)

SRC_LIBCACA	= $(LIBPATH)/Libcaca.cpp
OBJ_LIBCACA = $(SRC_LIBCACA:.cpp=.o)

SRC_LIBSDL	= $(LIBPATH)/SDL.cpp
OBJ_LIBSDL = $(SRC_LIBSDL:.cpp=.o)

SRC_SOLARFOX	= $(GAMEPATH)/solarfox/event.cpp \
								$(GAMEPATH)/solarfox/spaceobject/spaceobject.cpp \
								$(GAMEPATH)/solarfox/spaceobject/sfxhenemy.cpp \
								$(GAMEPATH)/solarfox/spaceobject/sfxvenemy.cpp \
								$(GAMEPATH)/solarfox/spaceobject/spaceship.cpp \
								$(GAMEPATH)/solarfox/spaceobject/spaceshipshoot.cpp \
								$(GAMEPATH)/solarfox/spaceobject/enemyshoot.cpp \
								$(GAMEPATH)/solarfox/spaceobject/powerup.cpp \
								$(GAMEPATH)/solarfox/spaceobject/obstacle.cpp \
								$(GAMEPATH)/solarfox/protocol.cpp \
								$(GAMEPATH)/solarfox/solarfox.cpp \
								$(GAMEPATH)/solarfox/logic.cpp \
								src/translator.cpp
OBJ_SOLARFOX = $(SRC_SOLARFOX:.cpp=.o)

SRC_SNAKE	= $(GAMEPATH)/snake/Snake.cpp \
		$(GAMEPATH)/snake/items/Body.cpp \
		src/translator.cpp


OBJ_SNAKE	= $(SRC_SNAKE:.cpp=.o)

SRC_DEBUG	= $(ARCADEPATH)/luncher.cpp \
						$(ARCADEPATH)/event.cpp \
						UniTest/protocol.cpp
OBJ_DEBUG = $(SRC_DEBUG:.cpp=.o)


all: $(GAMES) $(NAME) $(GRAPHIC)

$(NAME): $(OBJ)
	$(CXX) -o $(NAME) $(OBJ) -ldl

libcaca: $(OBJ_LIBCACA)
	$(CXX) -shared -o lib/lib_arcade_libcaca.so $(OBJ_LIBCACA) `pkg-config --libs --cflags caca`

sdl: $(OBJ_LIBSDL)
	$(CXX) -shared -o lib/lib_arcade_libsdl2.so $(OBJ_LIBSDL) -lSDL2 -lSDL2_ttf

solarfox: $(OBJ_SOLARFOX)
	$(CXX) -shared -o games/lib_arcade_solarfox.so $(OBJ_SOLARFOX)

snake: $(OBJ_SNAKE)
	$(CXX) -shared -o games/lib_arcade_snake.so $(OBJ_SNAKE)

debug: $(OBJ_DEBUG)
	$(CXX) -o debug $(OBJ_DEBUG) -ldl

clean:
	$(RM) $(OBJ_SOLARFOX)
	$(RM) $(OBJ_LIBCACA)
	$(RM) $(OBJ_LIBSDL)
	$(RM) $(OBJ_DEBUG)
	$(RM) $(OBJ)

fclean: clean
	$(RM) games/*.so
	$(RM) lib/*.so
	$(RM) debug
	$(RM) $(NAME)

re: fclean all

.PHONY: all, clean, fclean
