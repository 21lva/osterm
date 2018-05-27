#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include "alg.h"
#include <time.h>
#include <stdlib.h>

Result* FCFSA(process* parray[],int nump);
Result* PRIORITYA(process* parray[],int nump,int IsPreemptive);
Result* RRA(process* parray[],int nump, int TimeQuantum);
Result* SJFA(process* parray[],int nump,int IsPreemptive);

#endif
