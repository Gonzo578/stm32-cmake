#include "IObserver.h"
#include <stddef.h>

void OBS_CreateSubject(Subject_t* pSubject) {
    pSubject->pHead     = NULL;
}

void OBS_CreateObserver(Observer_t* pObserver, Observer_cb_t cb) {
    pObserver->p_next   = NULL;
    pObserver->p_prev   = NULL;
    pObserver->p_cb     = cb;
}

void OBS_Attach(Subject_t* pSubject, Observer_t* pObserver) {
    /**
     *  We always attach new observers at head of the list
     */
    pSubject->pHead->p_prev = pObserver;
    pObserver->p_next       = pSubject->pHead;
    pObserver->p_prev       = NULL;             // this should be already the case but we do it for sake of consistency
    pSubject->pHead         = pObserver;
}

void OBS_Detach(Subject_t* pSubject, Observer_t* pObserver) {
    /**
     *  Detaching can take place anywhere in the list
     */
    if(pObserver->p_prev == NULL) {
        // first element is to be detached
        pSubject->pHead = pObserver->p_next;
    } else {
        // any other element is to be detached
        pObserver->p_prev->p_next = pObserver->p_next;
    }
    pObserver->p_next = NULL;
    pObserver->p_prev = NULL;
}

void OBS_Notify(Subject_t* pSubject) {
    pObserver* pTmp = pSubject->pHead;

    //iterate over observer list and call all the update functions
    while(pTmp != NULL) {
        if(pTmp->p_cb != NULL) {
            pTmp->p_cb();
        }
        pTmp = pTmp->p_next;
    }
}