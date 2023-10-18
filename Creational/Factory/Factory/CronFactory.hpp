#pragma once
#include "CreateInterface.hpp"
#include "Crops/Crops.hpp"
#include "Crops/Corn.hpp"

class CornFactory : public CreateInterface
{
public:
    CornFactory() = default;
    virtual ~CornFactory() = default;

    Crops* Create() override
    {
        return new Corn();
    }
};