/*
GARTS (GENETIC ALGORITHM REAL TIME STRATEGY)
Created as part of honours assessment (CGT4 Abertay University)
Created by Samuel Cumming
Honours Supervisor: Dr. Craig Stark

Purpose: To determine whether GA powered AIs can increase replayability
and player enjoyment compared to conventional, static AIs.

Uses SDL2.0 as a back-end and is built from the ground up.
StartDate: 7/1/17
EndDate:   24/4/17

See https://github.com/forsamori/GARTS for github.
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
#include "MilitaryUnit.h"

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

//Execute GA activity
//Calculate candidate fitness
void CalcFitness();
//Select candidates by their fitness
void PlotRoulette(int noOfPicks);
//Cross-over successful candidates to generate new ones
void Recombine(AI* candidates[]);
//Mutate chromosome to prevent stale genetics.
void Mutate(AI* candidates[]);


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


//Mouse click timing controls
bool mouseDown;
float mouseDownTime;

//Mouse click position
vec2f clickStart;
vec2f clickCurrent;

//IMPORTANT - These vectors are the soul of the application.
//They carry references to all gameobjects. Be careful when editing them.
std::vector<GameObject*> gameObjectsRef;
std::vector<GameObject> gameObjects;

//Set up all AIs and identify them
AI ai1 = AI(&gameObjectsRef, &gameObjects, Owner::OWN_AI1);
AI ai2 = AI(&gameObjectsRef, &gameObjects, Owner::OWN_AI2);
AI ai3 = AI(&gameObjectsRef, &gameObjects, Owner::OWN_AI3);
AI ai4 = AI(&gameObjectsRef, &gameObjects, Owner::OWN_AI4);

//Hold fitness values.
float fitness_ai1;
float fitness_ai2;
float fitness_ai3;
float fitness_ai4;

float GA_TIMER;


// --- END Global Variables ---

#endif