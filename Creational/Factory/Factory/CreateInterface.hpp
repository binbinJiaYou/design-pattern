#pragma once
#include "Crops/Crops.hpp"

class CreateInterface
{
public:
    CreateInterface() = default;
    virtual ~CreateInterface() = default;
    virtual Crops* Create() = 0;
};