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
			for (int i = 0; i < gameObjectsRef->size(); i++)
			{
				if (gameObjectsRef->at(i)->owner == owner)
				{
					myUnits.push_back(gameObjectsRef->at(i));
				}
			}
			for (int j = 0; j < myUnits.size(); j++)
			{
				if (myUnits.at(j)->OT == OT_TOWNHALL)
					myTownhall = myUnits.at(j);
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
			break;
		}
		case AI_START_ARMY_PHASE:
		{
			
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

}
