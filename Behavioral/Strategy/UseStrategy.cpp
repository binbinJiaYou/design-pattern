/**
 * @file UseStrategy.cpp
 * @brief 使用策略模式
 *
 */
#include <iostream>

enum class PaymentType
{
    CREDIT = 0,
    WECHAT,
    ALIPAY,
    LENGHT_OF_PAYMENTTYPE
};

class PaymentStrategy
{
public:
    PaymentStrategy() = default;
    virtual ~PaymentStrategy() = default;
    virtual void Payment() = 0;
};

class CreditPaymentStrategy : public PaymentStrategy
{
public:
    CreditPaymentStrategy() = default;
    ~CreditPaymentStrategy() = default;
    void Payment() override
    {
        std::cout << "使用信用卡支付" << std::endl;
    }
};

class WechatPaymentStrategy : public PaymentStrategy
{
public:
    WechatPaymentStrategy() = default;
    ~WechatPaymentStrategy() = default;
    void Payment() override
    {
        std::cout << "使用微信支付" << std::endl;
    }
};

class AlipayPaymentStrategy : public PaymentStrategy
{
public:
    AlipayPaymentStrategy() = default;
    ~AlipayPaymentStrategy() = default;
    void Payment() override
    {
        std::cout << "使用支付宝支付" << std::endl;
    }
};

class PaymentService
{
public:
    void Payment(PaymentStrategy *strategy, size_t amount)
    {
        if (strategy)
        {
            strategy->Payment();
        }
    }
};

int main()
{
    PaymentService service;
    // 使用银行卡支付
    CreditPaymentStrategy credit;
    service.Payment(&credit, 114115);
    // 使用微信支付
    WechatPaymentStrategy wecaht;
    service.Payment(&wecaht, 114115);
    // 使用支付宝支付
    AlipayPaymentStrategy alipay;
    service.Payment(&alipay, 114115);
    return 0;
}