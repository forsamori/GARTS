#ifndef _AI_H
#define _AI_H

#include "GameObject.h"
#include "Worker.h"
#include "Townhall.h"
#include "Barracks.h"
#include <vector>


const float COST_SPEARMAN = 20.0f;
const float COST_ARCHER = 20.0f;
const float COST_KNIGHT = 30.0f;

//Overall AI states.
enum AI_STATE {
	AI_INIT,
	AI_DESTROY,
	AI_START_COLLECT_PHASE, //Collect resources, little to no fighting
	AI_START_ARMY_PHASE, //Start building army units, stop building resource units (unless new resources found/units destroyed)
	AI_RAID_PHASE, //Select a group of units and raid enemy resources.
	AI_MID_PHASE, //Active scouting, harrassing enemy workers
	AI_END_PHASE, //Full base assaults. If all units die, regress to AI_START_ARMY_PHASE
};

//AI raiding states
enum AI_RAID_STATE {
	RD_INIT, //Initialize and prep for raiding
	RD_SELECT_TARGET, //Select a raiding target
	RD_MOVE_TO_TARGET, //Move raiding party to target
	RD_ENGAGE, //Attack the target
	RD_RETREAT, //Retreat back to barracks.
	RD_EVALUATE //Determine if raid was successful.
};

class AI {

public:

	//AI genes.
	//When running in GA mode, these will be modified.
	//IMPORTANT: Make sure to add any new genes to the GA
	//recombination section in main.cpp
	float RAID_CHANCE = 30.0f;
	float RAID_COOLDOWN = 3000.0f;
	float NO_OF_RAIDERS = 5.0f;
	float DECISION_CHANCE = 0.005;
	float RETREAT_THRESHOLD = 2.0f;
	float NEWTARGET_CHANCE = 50.0f;

	float SPAWN_CHANCE_SPEARMAN = 100.0f;
	float SPAWN_CHANCE_ARCHER = 30.0f;
	float SPAWN_CHANCE_KNIGHT = 10.0f;


	//Create a new AI and set it up with everything it needs to run.
	AI(std::vector<GameObject*>* _gameObjectsRef, std::vector<GameObject>* _gameObjects, Owner _owner)
	{
		gameObjectsRef = _gameObjectsRef;
		gameObjects = _gameObjects;
		currAIState = AI_INIT;
		currRaidState = RD_INIT;
		owner = _owner;
		raidCooldown = RAID_COOLDOWN;
		killCount = 0;
		casualtyCount = 0;
		successfulEngagements = 0;
		maxUnits = 50;
	}
	~AI();

	void Update();

	//Unused
	void CalcFitness();
	void Recombine();
	void Mutate();
	//-----

	//Wrap the Chromosome to send to other classes.
	std::vector<float> WrapChromosome();

	//Return number of units owned
	int GetNoOfMyUnits();
	//Return number of current resources 
	int GetNoOfResources();
	//Return number of successful engagements
	int GetNoOfSuccessEngage();

protected:
private:

	std::vector<GameObject*>* gameObjectsRef;
	std::vector<GameObject>* gameObjects;
	std::vector<GameObject*> targetUnits;

	std::vector<GameObject*> myBuildings;
	std::vector<GameObject*> myUnits;
	std::vector<GameObject*> myRaiders;
	std::vector<GameObject*> enemyUnits;
	Townhall* myTownhall;
	Barracks* myBarracks;
	AI_STATE currAIState;
	AI_STATE prevAIState;
	AI_RAID_STATE currRaidState;
	Owner owner;
	//Find all units belonging to AI.
	void RefreshUnitList();
	float raidCooldown;

	int killCount;
	int casualtyCount;
	int successfulEngagements;
	int maxUnits;


};

#endif