# 工厂模式

## 1. 简介
工厂模式的目的：隐藏对象的创建工作，将对象的创建和使用**分离**，降低耦合度。

## 2. 简单工厂
简单工厂并不算一个设计模式，更像是一种编程习惯。  
定义一个用于创建对象的方法，传入一个参数用于判断创建哪一种实例。  
实例如下：
@@startuml
interface Crops
{
    + Plant(): void
}

class Tomato
{
    + Plant(): void
}

class Potato
{
    + Plant(): void
}

Crops <|.. Tomato
Crops <|.. Potato

class SimpleFactory 
{
    + Create(type): Crops*
}

Tomato <.. SimpleFactory
Potato <.. SimpleFactory
@@enduml
在上述实例中，Factory::create() 方法可以通过 type 判断创建哪种类型的农作物。
由此可见，简单工厂有以下缺点：
1. 不符合开闭原则，由于 Factory::create() 方法包含了创建哪种农作物的具体逻辑，因此，当需要添加另外一种农作物时，需要修改 Factory::create() 方法

## 3. 静态工厂
简单工厂需要实例化工厂对象才能生产对象，静态工厂使用静态的Create()方法避免工厂对象的创建

## 4. 工厂模式
简单工厂/静态工厂的缺点是每增加一种类型就需要修改判断逻辑。  
工厂模式首先定义一个创建对象的接口，由子类负责具体对象的创建，每一种子类只负责生产一种类型的产品，避免了需要判断生产哪种类型的产品。（以继承多态的方式实现判断）
@@startuml
interface CreateMethod
{
    + Create(): Crops*
}
TomatoFactory .down.|> CreateMethod
PotatoFactory .down.|> CreateMethod
CronFactory .down.|> CreateMethod

interface Crops
{
    + Plant(): void
}
Tomato .up.|> Crops
Potato .up.|> Crops
Cron .up.|> Crops

Tomato <.. TomatoFactory
Potato <.. PotatoFactory
Cron <.. CronFactory
@@endluml

## 5. 抽象工厂模式
在工厂模式中, 只创建一个对象, 而在抽象工厂模式中, 要创建一组对象
如图: 
@@startuml
interface CreateMethod
{
    + CreateCrops(): Crops*
    + CreateAnimal(): Animal*
}
FactoryOne ..|> CreateMethod
FactoryTwo ..|> CreateMethod
FactoryThree ..|> CreateMethod

interface Crops
{
    + Plant(): void
}
Tomato ..|> Crops
Potato ..|> Crops

interface Animal
{
    + Eat(): void
}
Cow ..|> Animal
Sheep ..|> Animal

FactoryOne ..> Cow
FactoryOne ..> Tomato
FactoryTwo ..> Sheep
FactoryTwo ..> Potato
FactoryThree ..> Cow
FactoryThree ..> Potato
@@enduml
在抽象工厂模式中，添加被创建的对象(例如家具)，那么所有的子类工厂都要被修改，维护成本极大，因此抽象工厂模式适用于被创建的一组对象很稳定的情况。