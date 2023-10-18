#pragma once
#include "CreateInterface.hpp"
#include "Crops/Crops.hpp"
#include "Crops/Potato.hpp"

class PotatoFactory : public CreateInterface
{
public:
    PotatoFactory() = default;
    virtual ~PotatoFactory() = default;

    Crops* Create() override
    {
        return new Potato();
    }
};