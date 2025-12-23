/*
 * File: coder_profile_timer.c
 *
 * Code generated for instrumentation.
 *
 * This file contains stub implementations of the instrumentation utility
 * functions. These stubs allow instrumented code to be compiled
 * into an executable that does not support collection of execution
 * instrumentation data.
 *
 */

#include "coder_profile_timer.h"

/* Code instrumentation offset(s) for model LW_ctrl_241029_1 */
#define profileStart_LW_ctrl_241029_1_offset 0
#define profileEnd_LW_ctrl_241029_1_offset 0

/* A function parameter may be intentionally unused */
#ifndef UNUSED_PARAMETER
# if defined(__LCC__)
#   define UNUSED_PARAMETER(x)
# else
#   define UNUSED_PARAMETER(x)         (void) (x)
# endif
#endif

#define xilProfilingTimerFreezeInternal() {}

void xilProfilingTimerFreeze(void)
{
}

#define xilProfilingTimerUnFreezeInternal() {}

void xilProfilingTimerUnFreeze(void)
{
}

#define profileStart(id)               {UNUSED_PARAMETER(id);}
#define profileEnd(id)                 {UNUSED_PARAMETER(id);}

/* Code instrumentation method(s) for model LW_ctrl_241029_1 */
void profileStart_LW_ctrl_241029_1(uint32_T sectionId)
{
  profileStart(profileStart_LW_ctrl_241029_1_offset + sectionId);
}

void profileEnd_LW_ctrl_241029_1(uint32_T sectionId)
{
  profileEnd(profileEnd_LW_ctrl_241029_1_offset + sectionId);
}
