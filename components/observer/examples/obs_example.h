#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "stdint.h"
#include "ISubject.h"
#include "IObserver.h"

typedef enum _ObsDemoState_t {
    ON,
    OFF
}ObsDemoState_t;

typedef struct _ObsExampleObj_t {
    ObsDemoState_t  State;
    uint32_t        counter;
    Subject_t       Subject;
}ObsExampleObj_t;

void OBS_CreateObserverDemo(ObsExampleObj_t* pObj);

uint8_t OBS_HandleOberverDemo(ObsExampleObj_t* pObj);

ObsDemoState_t OBS_GetDemoState(ObsExampleObj_t* pObj);

void OBS_AttachObserver(ObsExampleObj_t* pObj, Observer_t* pObserver);

void OBS_DetachObserver(ObsExampleObj_t* pObj, Observer_t* pObserver);

#ifdef __cplusplus
}
#endif