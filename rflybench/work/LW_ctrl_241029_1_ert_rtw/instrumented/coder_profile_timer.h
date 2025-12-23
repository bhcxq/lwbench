/*
 * File: coder_profile_timer.h
 *
 * Code generated for instrumentation.
 *
 */

#include "rtwtypes.h"

/* Pause/restart the timer while running code associated with storing and uploading the data. */
void xilProfilingTimerFreeze(void);
void xilProfilingTimerUnFreeze(void);

/* Code instrumentation method(s) for model LW_ctrl_241029_1 */
void profileStart_LW_ctrl_241029_1(uint32_T sectionId);
void profileEnd_LW_ctrl_241029_1(uint32_T sectionId);
