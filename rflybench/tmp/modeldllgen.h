
#pragma once

#define DLLGEN_EXPORT __declspec(dllexport)

#include"Lifting_wing_HIL_model_dll.h"
#define INTHR_LENS 16
#define INSIL_INT_LEN 8
#define INSIL_FLOAT_LEN 20
#define INCOL_LEN 20



extern "C" {

	DLLGEN_EXPORT void DllReInitModel();
	DLLGEN_EXPORT void DllInputPWMs(const double inPWMs[INTHR_LENS]);
	DLLGEN_EXPORT void DllInputTerrain(const double terrain);
	DLLGEN_EXPORT void DllInputSILs(const int inSILInts[INSIL_INT_LEN], const float inSILFLoats[INSIL_FLOAT_LEN]);
	DLLGEN_EXPORT void DllInputColls(const float inFloatsCollision[INCOL_LEN]);
	DLLGEN_EXPORT void DllInitPosAngState(const double initPosOffset[3], const double initAngOffset[3]);
	DLLGEN_EXPORT void Dllstep();
	DLLGEN_EXPORT void DlloutputSensors(MavLinkSensor * sensor);
	DLLGEN_EXPORT void DlloutputGPS(MavLinkGPS * gps);
	DLLGEN_EXPORT void DlloutputStateQuat(MavLinkStateQuat * quat);
	DLLGEN_EXPORT void DllDestroyModel();
	DLLGEN_EXPORT void DlloutModel3DInfo(MavVehileInfo * info);
}
