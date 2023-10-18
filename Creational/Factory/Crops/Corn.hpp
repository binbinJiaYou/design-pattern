#pragma once
#include <iostream>
#include "Crops.hpp"

class Corn : public Crops
{
public:
    Corn() = default;
    virtual ~Corn() = default;

    void Plant() override
    {
        std::cout << "种植玉米" << std::endl;
    }

private:
    std::string color = "黄色";
    std::string shape = "长长的椭圆";
};