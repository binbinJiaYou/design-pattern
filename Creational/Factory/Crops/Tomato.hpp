#pragma once
#include <iostream>
#include "Crops.hpp"

class Tomato : public Crops
{
public:
    Tomato() = default;
    virtual ~Tomato() = default;

    void Plant() override
    {
        std::cout << "种植西红柿" << std::endl;
    }

private:
    std::string color = "红色";
    std::string shape = "比较圆";
};