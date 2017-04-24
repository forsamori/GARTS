#include "AI.h"


AI::~AI()
{
}

void AI::Update()
{
	switch (currAIState)
	{
		//Initalise AI. Find owned units and add them to list.
		case AI_INIT:
		{
			RefreshUnitList();
			for (int j = 0; j < myUnits.size(); j++)
			{
				if (myUnits.at(j)->OT == ObjectType::OT_TOWNHALL)
					myTownhall = (Townhall*)myUnits.at(j);
				if (myUnits.at(j)->OT == ObjectType::OT_BARRACKS)
					myBarracks = (Barracks*)myUnits.at(j);
			}
			currAIState = AI_START_COLLECT_PHASE;
			break;
		}

		//start collecting resources. Tell worker to go to nearest resource
		case AI_START_COLLECT_PHASE:
		{
			for (int i = 0; i < myUnits.size(); i++)
			{
				if (myUnits.at(i)->OT == ObjectType::OT_UNIT_WORKER)
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
		//Start building units. Check for unit threshold then send units into raid.
		case AI_START_ARMY_PHASE:
		{
			for (int i = 0; i < myUnits.size(); i++)
			{
				if (myUnits.at(i)->OT == ObjectType::OT_UNIT_WORKER)
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
					if (myUnits.at(i)->OT == ObjectType::OT_UNIT_SPEARMAN)
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
				if (milCount < maxUnits)
				{
					float spawnResult = randf();
						//KNIGHT
					if (spawnResult < SPAWN_CHANCE_KNIGHT)
					{
					}
					//ARCHER
					else if (spawnResult < SPAWN_CHANCE_ARCHER &&
							spawnResult > SPAWN_CHANCE_KNIGHT)
					{
					}
					//SPEARMAN
					else if (spawnResult <= SPAWN_CHANCE_SPEARMAN &&
							spawnResult > SPAWN_CHANCE_ARCHER)
					{
						myBarracks->SpawnUnit(ObjectType::OT_UNIT_SPEARMAN, &myUnits);
						myTownhall->resources -= COST_SPEARMAN;
					}


					
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
		//Send units to raid, retreat when complete and evaluate.
		case AI_RAID_PHASE:
		{
			switch (currRaidState) //Issue here existing units get overwritten.
			{
				//Initialize raiding state, get raiding party from myunits.
			case RD_INIT:
			{
				int unitSelection = rand_range(0, myUnits.size()-1);
				if (myRaiders.size() < NO_OF_RAIDERS)
				{
					if (myUnits.at(unitSelection)->OT == ObjectType::OT_UNIT_SPEARMAN ||
						myUnits.at(unitSelection)->OT == ObjectType::OT_UNIT_ARCHER ||
						myUnits.at(unitSelection)->OT == ObjectType::OT_UNIT_KNIGHT)
					{
						if (myUnits.at(unitSelection)->inRaidingParty == false)
						{
							myUnits.at(unitSelection)->inRaidingParty = true;

							myRaiders.push_back(myUnits.at(unitSelection));
						}
					}
				}
				else
				{
					currRaidState = RD_SELECT_TARGET;
				}

				break;
			}
			//Find suitable target. Make sure not to select self as target!
			//Add target units to list.
			case RD_SELECT_TARGET:
			{
				for (int i = 0; i < gameObjectsRef->size(); i++)
				{
					if (gameObjectsRef->at(i)->owner != owner)
					{
						enemyUnits.push_back(gameObjectsRef->at(i));
					}
				}
				
				Owner targetOwner = Owner::OWN_NONE;								 //Remove 
				while (targetOwner == Owner::OWN_NONE || targetOwner == owner || targetOwner == Owner::OWN_P1)
				{
					targetOwner = static_cast<Owner>((rand() % 4) + 1); //TODO: Change this to 8
				}
				
				targetUnits.clear();
				for (int j = 0; j < enemyUnits.size(); j++)
				{
					if (enemyUnits.at(j)->owner == targetOwner)
					{
						targetUnits.push_back(enemyUnits.at(j));
					}
				}
				
				int randTarget = rand_range(0, targetUnits.size()-1);
				for (int k = 0; k < myRaiders.size(); k++)
				{
					myRaiders.at(k)->SetTarget(targetUnits.at(randTarget));
				}
				currRaidState = RD_MOVE_TO_TARGET;
				break;
			}
			//Move raiders towards target.
			//When in contact, move to engage (unit_state informs this)
			case RD_MOVE_TO_TARGET:
			{
				for (int i = 0; i < myRaiders.size(); i++)
				{
					if (myRaiders.at(i)->unit_state == UNIT_STATE::US_ENGAGE)
					{
						currRaidState = RD_ENGAGE;
					}
					myRaiders.at(i)->unit_state = UNIT_STATE::US_MOVE_ENGAGE;
				}

				//Select all myRaiders use MOVE_TO_POINT
				//on currentTarget
				//If within range, goto RD_ENGAGE
				break;
			}
				
			//Engage enemy units. Check enemy unit health
			//and increment killcount when units die.
			//Constantly check to see if enemy units destroyed.
			//if yes, retreat, else find new targets.
			case RD_ENGAGE:
			{

				for (int j = 0; j < targetUnits.size(); j++)
				{
					if (targetUnits.at(j)->GetHealth() <= 0)
					{
						targetUnits.erase(targetUnits.begin() + j);
						killCount++;
					}
				}

				for (int i = 0; i < myRaiders.size(); i++)
				{
					if (myRaiders.at(i)->currentTarget == NULL)
					{
						int newTargetChance = rand_range(0, 100);
						if (newTargetChance <= NEWTARGET_CHANCE)
						{
							if (targetUnits.size() > 0)
							{
								int randTarget = rand_range(0, targetUnits.size() - 1);
								myRaiders.at(i)->SetTarget(targetUnits.at(randTarget));
							}
							else
							{
								//Engagement complete
								currRaidState = RD_RETREAT;
							}
						}
						else
						{
							currRaidState = RD_RETREAT;
						}
					}
				}

				

				if (myRaiders.size() < RETREAT_THRESHOLD)
				{
					for (int j = 0; j < myRaiders.size(); j++)
					{
						myRaiders.at(j)->SetTarget(NULL);
					}
					currRaidState = RD_RETREAT;
				}

				break;
			}
			//Retreat back to home base. (This informs raiders to retreat, doesn't
			//do it for them)
			case RD_RETREAT:
			{
				for (int i = 0; i < myRaiders.size(); i++)
				{
					myRaiders.at(i)->unit_state = UNIT_STATE::US_RETREAT;
				}
				currRaidState = RD_EVALUATE;
				break;
			}
			//Deterimine if the engagement was successful.
			case RD_EVALUATE:
			{
				//Calculate remaining friendly units
				for (int i = 0; i < myRaiders.size(); i++)
				{
					if (myRaiders.at(i)->GetHealth() <= 0)
					{
						casualtyCount++;
					}
				}

				if (killCount > casualtyCount)
				{
					successfulEngagements++;
				}
				myRaiders.clear();
				enemyUnits.clear();
				targetUnits.clear();
				currAIState = AI_START_ARMY_PHASE;
				break;
			}
			default:
				break;
			}
			

			break;
		}
		case AI_MID_PHASE:
		{
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
	if (prevAIState == NULL || prevAIState != currAIState)
	{
		std::string currStateOut;
		std::string prevStateOut;

		switch (currAIState)
		{
		case AI_INIT:
			currStateOut = "AI_INIT";
			break;
		case AI_DESTROY:
			currStateOut = "AI_DESTROY";
			break;
		case AI_START_COLLECT_PHASE:
			currStateOut = "AI_START_COLLECT";
			break;
		case AI_START_ARMY_PHASE:
			currStateOut = "AI_START_ARMY";
			break;
		case AI_RAID_PHASE:
			currStateOut = "AI_RAID";
			break;
		case AI_MID_PHASE:
			currStateOut = "AI_MID";
			break;
		case AI_END_PHASE:
			currStateOut = "AI_MID";
			break;
		}

		switch (prevAIState)
		{
		case AI_INIT:
			prevStateOut = "AI_INIT";
			break;
		case AI_DESTROY:
			prevStateOut = "AI_DESTROY";
			break;
		case AI_START_COLLECT_PHASE:
			prevStateOut = "AI_START_COLLECT";
			break;
		case AI_START_ARMY_PHASE:
			prevStateOut = "AI_START_ARMY";
			break;
		case AI_RAID_PHASE:
			prevStateOut = "AI_RAID";
			break;
		case AI_MID_PHASE:
			prevStateOut = "AI_MID";
			break;
		case AI_END_PHASE:
			prevStateOut = "AI_MID";
			break;
		}
		std::string s = "AI: ";
		//s.append(std::to_string(owner).c_str());
		s.append(" entered STATE: ");
		s.append(currStateOut);
		s.append(" from STATE: ");
		s.append(prevStateOut);
		char* debugOut = (char*)s.c_str();

		Debug_String(debugOut);
	}

	if (myBarracks->GetHealth() <= 0)
	{
		currAIState = AI_DESTROY;
	}

	prevAIState = currAIState;

	

}

void AI::CalcFitness()
{
	
}

void AI::Recombine()
{
}

void AI::Mutate()
{
}

std::vector<float> AI::WrapChromosome()
{
	std::vector<float> chromosome;
	chromosome.push_back(RAID_CHANCE);
	chromosome.push_back(RAID_COOLDOWN);
	chromosome.push_back(NO_OF_RAIDERS);
	chromosome.push_back(DECISION_CHANCE);
	chromosome.push_back(RETREAT_THRESHOLD);
	chromosome.push_back(NEWTARGET_CHANCE);
	chromosome.push_back(SPAWN_CHANCE_ARCHER);
	chromosome.push_back(SPAWN_CHANCE_KNIGHT);
	chromosome.push_back(SPAWN_CHANCE_SPEARMAN);


	return chromosome;
}

int AI::GetNoOfMyUnits()
{
	return myUnits.size();
}

int AI::GetNoOfResources()
{
	return myTownhall->resources;
}

int AI::GetNoOfSuccessEngage()
{
	return successfulEngagements;
}

//Find units that belong to this AI.
//Was originally used to keep on top of units
//rapidly spawning and not being added to myUnits.
void AI::RefreshUnitList()
{
	Debug_String("Refreshing Unit List");
	myUnits.clear();
	Debug_String("Entering loop");
	for (int i = 0; i < gameObjectsRef->size(); i++)
	{
		
		std::string s = "Loop: ";
		s.append(std::to_string(i).c_str());
		char* debugOut = (char*)s.c_str();
		Debug_String(debugOut);

		if (gameObjectsRef->at(i)->owner == owner)
		{
			Debug_String("Push_Back");
			myUnits.push_back(gameObjectsRef->at(i));
		}
	}
}
