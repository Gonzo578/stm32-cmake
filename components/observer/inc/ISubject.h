#pragma once

#include "IObserver.h"
#include <stdint.h>

typedef struct _Subject_t {
    Observer_t* pHead;      //< pointer to the observer list
    uint32_t    cnt;        //< no of attached observers
}Subject_t;

void OBS_CreateSubject(Subject_t* pSubject);

void OBS_CreateObserver(Observer_t* pObserver, Observer_cb_t cb);

void OBS_Attach(Subject_t* pSubject, Observer_t* pObserver);

void OBS_Detach(Subject_t* pSubject, Observer_t* pObserver);

void OBS_Notify(Subject_t* pSubject);