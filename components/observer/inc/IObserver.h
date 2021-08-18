#pragma once

#include <stdint.h>

typedef void (*Observer_cb_t)(void);

typedef struct _Observer_t {
    struct _Observer_t* p_next;
    struct _Observer_t* p_prev;
    Observer_cb_t p_cb;
}Observer_t;

typedef struct _Subject_t {
    Observer_t* pHead;      //< pointer to the observer list
    uint32_t    cnt;        //< no of attached observers
}Subject_t;

void OBS_CreateSubject(Subject_t* pSubject);

void OBS_CreateObserver(Observer_t* pObserver, Observer_cb_t cb);

void OBS_Attach(Subject_t* pSubject, Observer_t* pObserver);

void OBS_Detach(Subject_t* pSubject, Observer_t* pObserver);

void OBS_Notify(Subject_t* pSubject);