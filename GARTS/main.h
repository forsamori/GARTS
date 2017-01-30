//IMPORTANT: The following implementation is currently set up to...
//...render using software on the CPU. Swap to GPU to allow...
//...CPU to concentrate on game-logic and GA...


#ifndef _MAIN_H
#define _MAIN_H

#include "SDL.h"
#include <windows.h> //OUTPUTDEBUGSTRING function
#include <stdio.h>
#include <iostream>
#include <sstream>

//Const definitions
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main();

//Initialise App: Set up SDL and create Window
bool init();

//Loads media files
bool loadMedia();

//Frees up media and shuts down SDL
void close();

//Helper Debug Function. Prints string to Debug output
void Debug_String(char* string);

//Declare SDL_ vars
SDL_Event _event;

//Declare control vars
bool quit;
// --- Global Variables ---

//Render Window
SDL_Window* gWindow = NULL;

//Window Surface (The surface we'll draw to)
SDL_Surface* gScreenSurface = NULL;

//Image to Render
SDL_Surface* gHelloWorld = NULL;

// --- END Global Variables ---

#endif