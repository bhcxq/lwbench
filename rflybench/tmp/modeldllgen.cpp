
#include"modeldllgen.h"

MulticopterModelClass mmc;

DLLGEN_EXPORT void DllCreatModel()
{

}

DLLGEN_EXPORT void DllReInitModel()
{
	mmc.initialize();
}

DLLGEN_EXPORT void DllInputPWMs(const double inPWMs[INTHR_LENS])
{
	for (int i = 0; i < INTHR_LENS; i++) {
		mmc.Lifting_wing_HIL_model_dll_U.inPWMs[i] = inPWMs[i];
	}
}

DLLGEN_EXPORT void DllInputSILs(const int inSILInts[INSIL_INT_LEN], const float inSILFLoats[INSIL_FLOAT_LEN])
{
	for (int i = 0; i < INSIL_INT_LEN; i++) {
		mmc.Lifting_wing_HIL_model_dll_U.inSILInts[i] = inSILInts[i];
	}

	for (int i = 0; i < INSIL_FLOAT_LEN; i++) {
		mmc.Lifting_wing_HIL_model_dll_U.inSILFloats[i] = inSILFLoats[i];
	}	
}


DLLGEN_EXPORT void DllInputColls(const float inFloatsCollision[INCOL_LEN])
{
	for (int i = 0; i < INCOL_LEN; i++) {
		mmc.Lifting_wing_HIL_model_dll_U.inFloatsCollision[i] = inFloatsCollision[i];
	}
}

DLLGEN_EXPORT void DllInputTerrain(const double terrain)
{
	mmc.Lifting_wing_HIL_model_dll_U.TerrainZ = terrain;
}

DLLGEN_EXPORT void DllInitPosAngState(const double initPosOffset[3], const double initAngOffset[3])
{
	mmc.Lifting_wing_HIL_model_dll_P.ModelInit_PosE[0] = initPosOffset[0];
	mmc.Lifting_wing_HIL_model_dll_P.ModelInit_PosE[1] = initPosOffset[1];
	mmc.Lifting_wing_HIL_model_dll_P.ModelInit_PosE[2] = initPosOffset[2];
	mmc.Lifting_wing_HIL_model_dll_P.ModelInit_AngEuler[2] = initAngOffset[2];


}

DLLGEN_EXPORT void Dllstep()
{
		mmc.step();

}

DLLGEN_EXPORT void DlloutputSensors(MavLinkSensor * sensor)
{
	memcpy(sensor, &mmc.Lifting_wing_HIL_model_dll_Y.MavHILSensor, sizeof(mmc.Lifting_wing_HIL_model_dll_Y.MavHILSensor));
}

DLLGEN_EXPORT void DlloutputGPS(MavLinkGPS * gps)
{
	memcpy(gps, &mmc.Lifting_wing_HIL_model_dll_Y.MavHILGPS, sizeof(mmc.Lifting_wing_HIL_model_dll_Y.MavHILGPS));
}

DLLGEN_EXPORT void DlloutputStateQuat(MavLinkStateQuat * quat)
{
	memcpy(quat, &mmc.Lifting_wing_HIL_model_dll_Y.MavHILStateQuat, sizeof(mmc.Lifting_wing_HIL_model_dll_Y.MavHILStateQuat));
}

DLLGEN_EXPORT void DllDestroyModel()
{
	mmc.terminate();
}

DLLGEN_EXPORT void DlloutModel3DInfo(MavVehileInfo * info)
{
    memcpy(info,&mmc.Lifting_wing_HIL_model_dll_Y.MavVehile3DInfo,sizeof(MavVehileInfo));
}
