call "C:\vs\VC\Auxiliary\Build\VCVARSALL.BAT " amd64

cd .
nmake -f Lifting_wing_HIL_model_dll.mk  GENERATE_ASAP2=0 OPTS="-DTID01EQ=1"
