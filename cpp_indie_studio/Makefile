DOC_DIR		= ./doc

NAME		= server client

CXX		= g++
CXXFLAGS	+= -I./include/irrlicht/ -I./include/ -I./include/menu -I./include/network -std=c++11
LIBS_SERVER	= -lpthread
LIBS_CLIENT	= -L./lib -lIrrlicht -lGL -lX11 -lXxf86vm -lpthread
RM		= rm -f

COMMON_SRC	= src/network/InternetSocket.cpp \
		src/network/InternetSocketError.cpp \
		src/network/OrderControler.cpp \
		src/ErrorControler.cpp

COMMON_OBJ	= $(COMMON_SRC:.cpp=.o)

SERVER_SRC	= $(COMMON_SRC) \
		src/Server.cpp

SERVER_OBJ	= $(SERVER_SRC:.cpp=.o)

CLIENT_SRC	= $(COMMON_SRC) \
		src/menu/Menu.cpp \
		src/menu/GraphicRoot.cpp \
		src/CommandControler.cpp \
		src/LoadCharacter.cpp \
		src/Position.cpp \
		src/Game.cpp \
		src/Mouvement.cpp \
		src/Character.cpp \
		src/Enemy.cpp \
		src/Player.cpp \
		src/Client.cpp \
		src/Camera.cpp

CLIENT_OBJ	= $(CLIENT_SRC:.cpp=.o)

all: $(NAME)

server: $(SERVER_OBJ)
	$(CXX) -o server $(SERVER_OBJ) $(LIBS_SERVER)

client: $(CLIENT_OBJ)
	$(CXX) -o client $(CLIENT_OBJ) $(LIBS_CLIENT)

clean:
	$(RM) $(SERVER_OBJ)
	$(RM) $(CLIENT_OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

# DOCUMENTATION #
$(DOC_DIR):
	@echo "[DOC]:Create $(DOC_DIR)"
	@mkdir $(DOC_DIR)	
$(DOC_DIR)doxyfile.mk: $(DOC_DIR)
	@echo "[DOC]:Generate doxyfile"
	@doxygen -g $(DOC_DIR)doxyfile.mk

	@echo "[DOC]:Setup project dependant fields"
	@sed -ie 's/^\(INPUT                  =\).*$$/\1 \./' $(DOC_DIR)doxyfile.mk
	@sed -ie 's/^\(FILE_PATTERNS          =\).*$$/\1 \*\.cpp \*\.hh/' $(DOC_DIR)doxyfile.mk
	@sed -ie 's/^\(PROJECT_NAME           =\).*$$/\1 $(EXE)/' $(DOC_DIR)doxyfile.mk
	@sed -ie 's/^\(OUTPUT_DIRECTORY       =\).*$$/\1 doc/' $(DOC_DIR)doxyfile.mk
	@sed -ie 's/^\(RECURSIVE              =\).*$$/\1 yes/' $(DOC_DIR)doxyfile.mk
	@sed -ie 's/^\(PROJECT_BRIEF          =\).*$$/\1 {EPITECH} C++ IndieStudio /' $(DOC_DIR)doxyfile.mk

doc: | $(DOC_DIR)
generate_doc: doc $(DOC_DIR)doxyfile.mk
	@doxygen -s $(DOC_DIR)doxyfile.mk

.PHONY: re all clean fclean doc generate_doc
