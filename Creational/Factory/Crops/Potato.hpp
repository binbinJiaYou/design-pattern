#pragma once
#include <iostream>
#include "Crops.hpp"

class Potato : public Crops
{
public:
    Potato() = default;
    virtual ~Potato() = default;

    void Plant() override
    {
        std::cout << "种植土豆" << std::endl;
    }

private:
    std::string color = "黄色";
    std::string shape = "比较长, 比较胖";
};