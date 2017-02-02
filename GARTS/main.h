//IMPORTANT (DONE, TEST): The following implementation is currently set up to...
//...render using software on the CPU. Swap to GPU to allow...
//...CPU to concentrate on game-logic and GA...

//TODO
/*
GameObject class
GameObject collision detection AA->BB bounding box
Mouse click input
Mouse drag input
GameObject move-to-point
GameObject health

//SEE MOVE TO POINT
*/


#ifndef _MAIN_H
#define _MAIN_H

#include "SDL.h"
#include <windows.h> //OUTPUTDEBUGSTRING function
#include <stdio.h>
#include <iostream>
#include <sstream>

//Custom class
#include "texture.h"
#include "Sprite.h"
#include "GameObject.h"
#include "helper_functions.h"

//Const definitions
const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 768;

//KeyPress definitions
enum ENUM_KEYPRESS
{
	KEYPRESS_UP,
	KEYPRESS_DOWN,
	KEYPRESS_LEFT,
	KEYPRESS_RIGHT
};

int main();

//Initialise App: Set up SDL and create Window
bool init();

//Loads media files
bool loadMedia();

//Frees up media and shuts down SDL
void close();

//Poll and react to inputs here
void Input();

void Update();

void Render();


//Helper Debug Function. Prints string to Debug output
//void Debug_String(char* string);

//int Lerp(float t, int a, int b);

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
SDL_Surface* gBackground = NULL;

//Title image
Texture gTitle;

Texture tBackground;

Sprite sMan;

GameObject test_object;

SDL_Renderer* gRenderer = NULL;

// --- END Global Variables ---

#endif