#pragma once

typedef void (*Observer_cb_t)(void);

typedef struct _Observer_t {
    struct _Observer_t* p_next;
    struct _Observer_t* p_prev;
    Observer_cb_t p_cb;
}Observer_t;
