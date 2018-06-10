#include "queue.h"
#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define TIME_UNIT 100

static struct pqueue_t in_queue;
static struct_pqueue_t ready_queue;

static int load_done = 0;

static int timeslot;

void *cpu