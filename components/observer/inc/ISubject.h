#pragma once

#include "IObserver.h"
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _Subject_t {
    Observer_t* pHead;      //< pointer to the observer list
    uint32_t    cnt;        //< no of attached observers
}Subject_t;

void OBS_CreateSubject(Subject_t* pSubject);

void OBS_Attach(Subject_t* pSubject, Observer_t* pObserver);

void OBS_Detach(Subject_t* pSubject, Observer_t* pObserver);

void OBS_Notify(Subject_t* pSubject);

#ifdef __cplusplus
}
#endif
