#include <iostream>
#include <time.h>
#include <ncurses.h>
#include <limits>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "Persona.h"
#include "Dado.h"
#include "Type.h"
#include"Coda.h"
#include "deck.h"
#include "Giocatori.h"
#include "Nodo.h"
#include "Tabellone.h"
#define COL(x) "\033[" #x ";1m"
#define COL_RED COL(31)
#define COL_GREEN COL(32)
#define COL_YELLOW COL(33)
#define COL_BLUE COL(34)
#define COL_PINK COL(35)
#define COL_SKY COL(36)
#define COL_WHITE COL(37)
#define COL_CLEAR "\033[0m"
using namespace std;
#if 0
#include <GL/glew.h>
#include <GLFW/glfw3.h>
GLFWwindow* window;
#include <glm/glm.hpp>
using namespace glm;
#endif
