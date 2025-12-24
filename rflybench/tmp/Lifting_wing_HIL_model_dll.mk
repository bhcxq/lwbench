Lifting_wing_HIL_model_dll.dll: modeldllgen.obj Lifting_wing_HIL_model_dll.obj
	cl modeldllgen.obj Lifting_wing_HIL_model_dll.obj /link /DLL /out:Lifting_wing_HIL_model_dll.dll
modeldllgen.obj: modeldllgen.h Lifting_wing_HIL_model_dll.obj
	cl /c /EHsc modeldllgen.cpp
Lifting_wing_HIL_model_dll.obj: rtw_continuous.h rtw_solver.h Lifting_wing_HIL_model_dll.h coder_bounded_array.h rtwtypes.h
	cl /c /EHsc Lifting_wing_HIL_model_dll.cpp
