#ifndef PID_H
#define PID_H

#include "Utils.h"

typedef struct
{
    float kp;
    float kd;
    float ki;
}CORRECTOR_PARAMETERS;

typedef struct
{
    CORRECTOR_PARAMETERS correctorValues;
    int errorGap[3];
    int current;
    int goal;
}PID_VALUE;

#define InitializationPid(pid, value, newKp, newKi, newKd)\
{\
    int i;\
    \
    for(i = 0; i<3; i++)\
    {\
    pid.errorGap[i] = 0;\
    }\
    \
    pid.current = 0;\
    pid.goal = value;\
    pid.correctorValues.kp = newKp;\
    pid.correctorValues.kd = newKd;\
    pid.correctorValues.ki = newKi;\
}\

#define PCalculation(pid)\
{\
    pid.current += pid.correctorValues.kp*(pid.errorGap[0] - pid.errorGap[1]);\
}\

#define ICalculation(pid, T)\
{\
    pid.current += pid.correctorValues.ki*pid.errorGap[0]*T;\
}\

#define DCalculation(pid, T)\
{\
    pid.current += pid.correctorValues.kp*(pid.errorGap[0] - pid.errorGap[1]*2 + pid.errorGap[2]);\
}\

#define FinalValueCalculation(pid, T, currentValue)\
{\
    pid.errorGap[2] = 0;\
    Swap(pid.errorGap[2],pid.errorGap[1])\
    Swap(pid.errorGap[1],pid.errorGap[0])\
    Swap(pid.current, pid.goal)\
    pid.current = currentValue;\
    pid.errorGap[0] = pid.goal - pid.current;\
    PCalculation(pid)\
    ICalculation(pid, T)\
    DCalculation(pid, T)\
}\

#endif