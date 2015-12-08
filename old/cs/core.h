#ifndef CORE_H
#define CORE_H
#include "scientists.h"
#include "computers.h"
#include "service.h"
#include "display.h"
#include "core.h"

class core
{
public:
    void controller(vector<scientists> &cs, vector<computers> &c);  //  Main controller for program. (UI)
};

#endif // CORE_H
