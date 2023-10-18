/**
 * @file Factory.cpp
 * @brief 工厂模式
 * 增加新类型的农作物只需添加相应的工厂子类即可，不需要修改原有代码
 */
#include <iostream>
#include <vector>
#include <unordered_map>
#include "Crops/Crops.hpp"
#include "Factory/CreateInterface.hpp"
#include "Factory/TomatoFactory.hpp"
#include "Factory/PotatoFactory.hpp"
#include "Factory/CronFactory.hpp"

enum class CropsType
{
    TOMATO = 0,
    POTATO,
    // CORN,
    LENGTH_OF_CROPSTYPE
};

int main()
{
    std::vector<CropsType> types {
        // CropsType::CORN,
        // CropsType::CORN,
        CropsType::TOMATO,
        CropsType::POTATO,
        CropsType::POTATO,
        CropsType::POTATO
    };

    std::unordered_map<CropsType, CreateInterface*> map {
        // { CropsType::CORN, new CornFactory() },
        { CropsType::TOMATO, new TomatoFactory() },
        { CropsType::POTATO, new PotatoFactory() }
    };

    std::vector<Crops*> crops;
    for(const auto& type : types)
    {
        Crops* tmp = map[type]->Create();
        crops.push_back(tmp);
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

    for(auto it = map.begin(); it != map.end(); it++)
    {
        delete (*it).second;
        (*it).second = nullptr;
    }

    return 0;
}