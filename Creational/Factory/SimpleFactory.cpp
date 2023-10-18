/**
 * @file SimpleFactory.cpp
 * @brief 简单工厂
 * Create() 方法包含了具体的创建逻辑
 */

#include <iostream>
#include <vector>
#include "Crops/Tomato.hpp"
#include "Crops/Potato.hpp"
#include "Crops/Corn.hpp"

enum class CropsType
{
    TOMATO = 0,
    POTATO,
    // CORN,
    LENGTH_OF_CROPSTYPE
};

class SimpleFactory
{
public:
    SimpleFactory() = default;
    ~SimpleFactory() = default;

    // 每添加一种类型
    // Create() 方法都要被修改
    Crops *Create(CropsType type)
    {
        if (type == CropsType::TOMATO)
        {
            return new Tomato();
        }
        else if (type == CropsType::POTATO)
        {
            return new Potato();
        }
        // else if (type == CropsType::CORN)
        // {
        //     return new Corn();
        // }

        return nullptr;
    }
};

int main()
{
    std::vector<CropsType> types{
        // CropsType::CORN,
        // CropsType::CORN,
        CropsType::TOMATO,
        CropsType::POTATO,
        CropsType::POTATO,
        CropsType::POTATO
    };

    SimpleFactory factory;
    std::vector<Crops *> crops;
    for (const auto &type : types)
    {
        crops.push_back(factory.Create(type));
    }

    for (auto &crop : crops)
    {
        crop->Plant();
    }

    while (!crops.empty())
    {
        Crops *tmp = crops.at(crops.size() - 1);
        delete tmp;
        crops.pop_back();
    }

    return 0;
}