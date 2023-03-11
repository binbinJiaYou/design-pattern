/**
 * @file Common.h
 * @author liubin (15085776458@163.com)
 * @brief 观察者模式的进一步讨论
 * @version 0.1
 * @date 2023-03-11
 *
 * @copyright Copyright (c) 2023
 *
 * 气象数据（ObserverPattern-1.cpp）是观察者模式的一个简单示例。
 * 假如我想要在加另外的主题（例如以一个人的一生为主题），你会发现抽象类 Observer 中的 Update 方法已经不适用了，再重新写一个又会有很多的重复代码（逻辑上是重复的）。
 * 有没有办法让代码适应更多主题的情况。
 *
 * Update 在某个具体的主题下的参数列表是固定的
 */
#pragma once

/**
 * @brief 使用泛型可以适应不同的主题
 *
 */
namespace ObserverPattern
{
    template <typename... Args>
    class Observer
    {
    public:
        Observer() = default;
        virtual ~Observer() = default;

        virtual void Update(Args... args) = 0;
    };

    template <typename... Args>
    class Subject
    {
    public:
        Subject() = default;
        virtual ~Subject() = default;

        virtual void Register(Observer<Args...> &Observer) = 0;
        virtual void Unregister(Observer<Args...> &Observer) = 0;
        virtual void Notify() = 0;
    };
};