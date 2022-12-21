#include "obs_example.h"
#include "ISubject.h"
#include <stdint.h>

void OBS_CreateObserverDemo(ObsExampleObj_t* pObj) {
    pObj->State     = ON;
    pObj->counter   = 0;
    OBS_CreateSubject(&pObj->Subject);
}

uint8_t OBS_HandleOberverDemo(ObsExampleObj_t* pObj) {
    pObj->counter++;

    if(pObj->counter >= 1000000) {
        pObj->counter = 0;

        if(pObj->State == ON) {
            pObj->State = OFF;
        } else {
            pObj->State = ON;
        }
        OBS_Notify(&pObj->Subject);
    }

    return 0;
}

ObsDemoState_t OBS_GetDemoState(ObsExampleObj_t* pObj) {
    return pObj->State;
}

void OBS_AttachObserver(ObsExampleObj_t* pObj, Observer_t* pObserver) {
    OBS_Attach(&pObj->Subject, pObserver);
}

void OBS_DetachObserver(ObsExampleObj_t* pObj, Observer_t* pObserver) {
    OBS_Detach(&pObj->Subject, pObserver);
}