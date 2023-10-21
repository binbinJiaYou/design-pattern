/**
 * @file UnuseStrategy.cpp
 * @brief 未使用策略模式
 *
 */
#include <iostream>
#include <cstdint>
#include <exception>

enum class PaymentType
{
    CREDIT = 0,
    WECHAT, 
    ALIPAY,
    LENGHT_OF_PAYMENTTYPE
};

class CreditService
{
public:
    void Payment()
    {
        std::cout << "银行卡支付" << std::endl;
    }
};

class WeChatService
{
public:
    void Payment()
    {
        std::cout << "微信支付" << std::endl;
    }
};

class AlipayService
{
public:
    void Payment()
    {
        std::cout << "支付宝支付" << std::endl;
    }
};

class PaymentService 
{
public:
    void Payment(PaymentType paymentType, size_t amount)
    {
        if (PaymentType::CREDIT == paymentType) {
            creditService.Payment();
        } else if (PaymentType::WECHAT == paymentType) {
            weChatService.Payment();
        } else if (PaymentType::ALIPAY == paymentType) {
            alipayService.Payment();
        }
    }

private:
    CreditService creditService;
    WeChatService weChatService;
    AlipayService alipayService;   
};

int main()
{
    PaymentService service;
    // 使用银行卡支付
    service.Payment(PaymentType::CREDIT, 114115);
    // 使用微信支付
    service.Payment(PaymentType::WECHAT, 114115);
    // 使用支付宝支付
    service.Payment(PaymentType::ALIPAY, 114115);

    return 0;
}