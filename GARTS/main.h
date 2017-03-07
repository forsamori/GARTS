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

Once a building is selected, pop up health and build buttons.
The button should be overlayed on top of the building for easy pressing.
Treat it as a gameobject to prevent code-repetition.

//It's dangerous to go alone: Read this for virtual function fun.
//TODO:: Barracks update needs to be called. We want Barracks::Update to run first, then GameObject::Update. Read the below tutorial.
http://www.cplusplus.com/doc/tutorial/polymorphism/


CURRENT: Get Barracks UI button to spawn units. Right now it can be selected (AS IF IT WERE A NORMAL GAMEOBJECT)...
...We don't want this. Instead, make it behave like a UI element (i.e it cannot be selected, only clicked and an action fired).

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
#include "Selector.h"
#include "Barracks.h"
#include "UI.h"
#include "UnitManager.h"
#include "Global.h"
#include "Resource.h"
#include "Worker.h"
#include "Townhall.h"
#include "AI.h"

//Const definitions
const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 768;
const float MOUSE_DOWN_THRESHOLD = 5.0f;

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

//void SpawnUnit(GameObject spawnObject);


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
GameObject test_object2;
GameObject test_object3;

SDL_Renderer* gRenderer = NULL;

Selector selection;



bool mouseDown;
float mouseDownTime;

//extern bool beginSpawn;

vec2f clickStart;
vec2f clickCurrent;

std::vector<GameObject*> gameObjectsRef;
std::vector<GameObject> gameObjects;

AI ai1 = AI(&gameObjectsRef, &gameObjects, OWN_AI1);
AI ai2 = AI(&gameObjectsRef, &gameObjects, OWN_AI2);
AI ai3 = AI(&gameObjectsRef, &gameObjects, OWN_AI3);

//UnitManager unitManager;

// --- END Global Variables ---

#endif