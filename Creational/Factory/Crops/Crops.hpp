#pragma once

class Crops
{
public:
    Crops() = default;
    virtual ~Crops() = default;
    virtual void Plant() = 0;
};