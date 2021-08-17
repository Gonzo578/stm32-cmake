#include "IObserver.h"
#include "ISubject.h"
#include <stddef.h>

void OBS_CreateSubject(Subject_t* pSubject) {
    pSubject->pHead     = NULL;
}

void OBS_CreateObserver(Observer_t* pObserver, Observer_cb_t cb) {
    pObserver->p_next   = NULL;
    pObserver->p_prev   = NULL;
    pObserver->p_cb     = cb;
}
