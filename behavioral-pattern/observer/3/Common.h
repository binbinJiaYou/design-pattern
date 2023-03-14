/**
 * @file Common.h
 * @author liubin (15085776458@163.com)
 * @brief 观察者模式进一步优化
 * @version 0.1
 * @date 2023-03-12
 *
 * @copyright Copyright (c) 2023
 *
 * 抽象观察者只有一个 Update 方法，可以使用 可调用对象 替代它
 */
#pragma once
#include <functional>

namespace ObserverPattern
{
    template <typename... Args>
    class Subject
    {
    public:
        Subject() = default;
        virtual ~Subject() = default;

        using Observer = std::function<void(Args...)>;
        virtual void Register(Observer &observer) = 0;
        virtual void Unregister(Observer &observer) = 0;
        virtual void Notify() = 0;
    };
};