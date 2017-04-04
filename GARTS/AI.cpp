#include "AI.h"

AI::~AI()
{
}

void AI::Update()
{
	switch (currAIState)
	{
		case AI_INIT:
		{
			RefreshUnitList();
			for (int j = 0; j < myUnits.size(); j++)
			{
				if (myUnits.at(j)->OT == OT_TOWNHALL)
					myTownhall = (Townhall*)myUnits.at(j);
				if (myUnits.at(j)->OT == OT_BARRACKS)
					myBarracks = (Barracks*)myUnits.at(j);
			}
			currAIState = AI_START_COLLECT_PHASE;
			break;
		}

		case AI_START_COLLECT_PHASE:
		{
			for (int i = 0; i < myUnits.size(); i++)
			{
				if (myUnits.at(i)->OT == OT_UNIT_WORKER)
				{
					Worker* tempWorker = (Worker*)myUnits.at(i);


					if (tempWorker->noMoreResources == true)
					{
						tempWorker->worker_state = WS_IDLE;
					}
					else if (tempWorker->worker_state != WS_COLLECT_GOTO && tempWorker->worker_state != WS_COLLECT_RETURN)
					{
						tempWorker->resourceHome = myTownhall;
						tempWorker->worker_state = WS_COLLECT_INIT;
						tempWorker->CollectCycle();
					}
				}
			}
			if (myTownhall->resources >= 100)
			{
				currAIState = AI_START_ARMY_PHASE;
			}
			break;
		}
		case AI_START_ARMY_PHASE:
		{
			for (int i = 0; i < myUnits.size(); i++)
			{
				if (myUnits.at(i)->OT == OT_UNIT_WORKER)
				{
					Worker* tempWorker = (Worker*)myUnits.at(i);


					if (tempWorker->noMoreResources == true)
					{
						tempWorker->worker_state = WS_IDLE;
					}
					else if (tempWorker->worker_state != WS_COLLECT_GOTO && tempWorker->worker_state != WS_COLLECT_RETURN)
					{
						tempWorker->resourceHome = myTownhall;
						tempWorker->worker_state = WS_COLLECT_INIT;
						tempWorker->CollectCycle();
					}
				}
			}
			//Run worker logic
			//Get the barracks spawning new units
			//Deduct unit cost from AI resources.
			if (myTownhall->resources > 100)
			{
				int milCount = 0;
				for (int i = 0; i < myUnits.size(); i++)
				{
					//TODO: Refactor this to point to spearmen
					if (myUnits.at(i)->OT == OT_UNIT_SPEARMAN)
					{
						milCount++;
					}
				}
				if (milCount >= 5)
				{
					
					float decisionResult = randf();
					if (decisionResult < DECISION_CHANCE)
					{
						float randResult = randf();
						if (randResult < RAID_CHANCE && raidCooldown <= 0.0f)
						{
							raidCooldown = RAID_COOLDOWN;
							currAIState = AI_RAID_PHASE;
						}
					}
				}
				else
				{
					myBarracks->SpawnUnit();
					myTownhall->resources -= COST_SPEARMAN;
					RefreshUnitList();
				}
				raidCooldown--;
			
				//If no_of_spearmen < 5
				//Build spearman
				//else
				//proceed to raiding phase 
				//OR
				//build military building
				//LOOP
				
				//if no_of_mil_units > 25
				//goto AI_MID_PHASE
			}
			//Run unit construction logic
			//Run building construction logic
			
			break;
		}
		case AI_MID_PHASE:
		{
			//run worker logic
			//run construction logic
			//Calculate what enemies to attack
			//Mass units at rally point
			//Send units to target
			//Analyse battle
				//If enemy destroyed, return home
				//If units drop below threshold, return home
				//If units return home above threshold, attack successful
				//If units don't return home, attack fail.
			//If attack successful, construct more of the same units and attack the same target
			//Else, construct more units and attack different AI.
			//If no_of_military units > 45 && military buildings > 6 && remaining players < 4
			//goto AI_END_PHASE
			break;
		}
		case AI_END_PHASE:
		{
			break;
		}
		case AI_DESTROY:
		{
			break;
		}
	}

}

void AI::RefreshUnitList()
{
	myUnits.clear();
	for (int i = 0; i < gameObjectsRef->size(); i++)
	{
		if (gameObjectsRef->at(i)->owner == owner)
		{
			myUnits.push_back(gameObjectsRef->at(i));
		}
	}
}
