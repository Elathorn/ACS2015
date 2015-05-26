#include "Mission.h"


Mission::Mission (String name, int missionDif, int soft, int hard, int air, int naval, int asw, int sead, int view, int mobility, int aircraft, 
				 int heli, int pointsReward, int scoutReward, int machineHPLossOnWin, int pointsLoss, int scoutLoss, 
				 int machineHPLossOnLose, int carrierHPLoss, String missionInfo, String missionWin, String missionLose)
{
	_name=name;
	_missionDifficulty = missionDif;
	_softAttackMod = soft;
	_hardAttackMod = hard;
	_airAttackMod = air;
	_navalAttackMod = naval;
	_ASWAttackMod = asw;
	_SEADAttackMod = sead;
	_viewMod = view;
	_mobilityMod = mobility;
	_aircraftMod = aircraft;
	_helicopterMod = heli;
	_pointsReward = pointsReward;
	_scoutReward = scoutReward;
	_machineHPLossOnWin = machineHPLossOnWin;
	_pointsLoss = pointsLoss;
	_scoutLoss = scoutLoss;
	_machineHPLossOnLose = machineHPLossOnLose;
	_carrierHPLoss = carrierHPLoss;
	_missionInfo = missionInfo;
	_missionWin = missionWin;
	_missionLose = missionLose;
}


Mission::~Mission(void)
	{
	}
