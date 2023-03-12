/**
 * @file Life.h
 * @author liubin (15085776458@163.com)
 * @brief 观察者模式的进一步讨论
 * @version 0.1
 * @date 2023-03-11
 *
 * @copyright Copyright (c) 2023
 *
 * 人的一生同样也是一个具体的主题
 */
#pragma once
#include <iostream>
#include <cmath>
#include <set>
#include <map>
#include "Common.h"

namespace LifeSubject
{
    enum class Stage;
    using Subject = ObserverPattern::Subject<Stage>;

    // 一个人一生的阶段
    enum class Stage
    {
        CHILD = 0,
        YOUNG,
        ADULT,
        OLD,
        STAGE_LENGTH
    };

    // 外貌观察者
    class AppearanceObserver
    {
    public:
        AppearanceObserver() : stage(Stage::CHILD) {}
        ~AppearanceObserver() = default;

        void operator()(Stage stage)
        {
            this->stage = stage;
            std::cout << "她现在看起来" << appearanceMap[this->stage] << std::endl;
            std::cout << "================================" << std::endl;
        }

    private:
        static std::map<Stage, std::string> appearanceMap;
        Stage stage;
    };
    std::map<Stage, std::string> AppearanceObserver::appearanceMap{
        {Stage::CHILD, "很稚嫩"},
        {Stage::YOUNG, "很可爱"},
        {Stage::ADULT, "很性感"},
        {Stage::OLD, "很和蔼"},
        {Stage::STAGE_LENGTH, "..., 她难道想成仙吗? !!!"}};

    // 身高观察者
    class HeightObserver
    {
    public:
        HeightObserver() : stage(Stage::CHILD) {}
        ~HeightObserver() = default;

        void operator()(Stage stage)
        {
            this->stage = stage;
            std::cout << "她现在看起来" << heightMap[this->stage] << std::endl;
            std::cout << "================================" << std::endl;
        }

    private:
        static std::map<Stage, std::string> heightMap;
        Stage stage;
    };
    std::map<Stage, std::string> HeightObserver::heightMap{
        {Stage::CHILD, "小小的"},
        {Stage::YOUNG, "有一点长高了，但还是小小的"},
        {Stage::ADULT, "已经长大了，变得亭亭玉立了"},
        {Stage::OLD, "有点佝偻了"},
        {Stage::STAGE_LENGTH, "..., 她难道想成仙吗? !!!"}};

    class Life : public Subject
    {
    public:
        Life() : stage(Stage::CHILD) {}
        ~Life() = default;

        void SetStage(Stage stage)
        {
            this->stage = stage;
        }

        void Register(Observer &observer) override
        {
            observerSet.insert(&observer);
        }

        void Unregister(Observer &observer) override
        {
            observerSet.erase(&observer);
        }

        void Notify() override
        {
            for (auto &observer : observerSet)
            {
                if (observer)
                {
                    (*observer)(stage);
                }
            }
        }

    private:
        Stage stage;
        std::set<Observer *> observerSet;
    };

    class Client
    {
    public:
        void SetStage(Life &life, Stage stage)
        {
            life.SetStage(stage);
            life.Notify();
        }
    };
};
