#pragma once
#include "CreateInterface.hpp"
#include "Crops/Crops.hpp"
#include "Crops/Tomato.hpp"

class TomatoFactory : public CreateInterface
{
public:
    TomatoFactory() = default;
    virtual ~TomatoFactory() = default;

    Crops* Create() override
    {
        return new Tomato();
    }
};