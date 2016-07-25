##
## Makefile for indie studio in /home/rigola_s/rendu/C++/cpp_indie_studio
## 
## Made by Rigolat Sébastien
## Login   <rigola_s@epitech.net>
## 
## Started on  Mon May  2 00:01:51 2016 Rigolat Sébastien
## Last update Sun Jun  5 23:38:19 2016 Rigolat Sébastien
##

NAME		=	indie_studio

CXX		=	g++

RM		=	rm -f

PATH_SRCS	=	./srcs/

CFLAGS		+=	-W
CFLAGS		+=	-Wall
CFLAGS		+=	-Wextra
CFLAGS		+=	-Werror
CFLAGS		+=	-std=gnu++11

LDFLAGS		+=	-I./include/
LDFLAGS		+=	-I./include/Common/Managers
LDFLAGS		+=	-I./include/Common/Save
LDFLAGS		+=	-I./include/Common/Error
LDFLAGS		+=	-I./include/IA
LDFLAGS		+=	-I./include/GUI
LDFLAGS		+=	-I./include/Controllers
LDFLAGS		+=	-I./include/Objects
LDFLAGS		+=	-I./include/Irrlicht
LDFLAGS		+=	-I./include/Core

LDLIBS		+=	-Llib/
LDLIBS		+=	-L/usr/lib64
LDLIBS		+=	-L/usr/X11R6/lib

LDLIBS		+=	-lIrrlicht
LDLIBS		+=	-lGL
LDLIBS		+=	-lXxf86vm
LDLIBS		+=	-lXext
LDLIBS		+=	-lX11
LDLIBS		+=	-lXcursor
LDLIBS		+=	-lpthread

SRC		=	main.cpp				\
			Common/Managers/MenuManager.cpp		\
			Common/Managers/GameManager.cpp		\
			Common/Error/Errors.cpp			\
			GUI/HUD.cpp				\
			GUI/OptionMenu.cpp			\
			GUI/PlaySubMenu.cpp			\
			GUI/GUIBonus.cpp			\
			GUI/MainMenu.cpp			\
			GUI/CreditsMenu.cpp			\
			GUI/PauseMenu.cpp			\
			GUI/AGUIMenu.cpp			\
			GUI/CharacterInfo.cpp			\
			GUI/PlayMenu.cpp			\
			Core/Core.cpp				\
			Objects/Map.cpp				\
			Objects/Fire.cpp			\
			Objects/Box.cpp				\
			Objects/Plan.cpp			\
			Objects/Character.cpp			\
			Objects/Bomb.cpp			\
			Objects/Object.cpp			\
			Controllers/KeyReceiver.cpp		\
			Controllers/PlayerController.cpp

SRCS		=	$(addprefix $(PATH_SRCS), $(SRC))

OBJS		=	$(SRCS:.cpp=.o)

%.o : 		%.cpp
		@echo "g++ -c -o $@ $^"
		@$(CXX) -c -o $@ $^ $(CFLAGS) $(LDFLAGS) $(LDLIBS)

$(NAME):	$(OBJS)
		@$(CXX) -o $(NAME) $(OBJS) $(CFLAGS) $(LDFLAGS) $(LDLIBS)
		@echo -e "g++ -o $(NAME)"

all:		$(NAME)

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
