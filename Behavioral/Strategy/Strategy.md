# 策略模式

## 1. 简介
当一个业务有多种处理方式，并且需要在运行时选择使用哪种处理方式时，可以考虑使用策略模式。

## 2. 具体场景
在电商支付场景中，有多种支付方式，例如使用银行卡，微信或者支付宝等，那么实际在支付系统内部，不同的支付方式需要请求不同的第三方接口，比如银行卡支付方式需要请求网联，微信支付需要调用微信的API，支付宝则使用支付宝的API。
![支付场景](https://p3-juejin.byteimg.com/tos-cn-i-k3u1fbpfcp/dba3eb09efd145e38be14f4e6d902efc~tplv-k3u1fbpfcp-zoom-in-crop-mark:1512:0:0:0.awebp)

### 2.1 不使用策略模式
很自然的想法，是使用 if-else 实现选择不同的支付方式。
```C++
enum class PaymentType
{
    CREDIT = 0,
    WECHAT, 
    ALIPAY,
    LENGHT_OF_PAYMENTTYPE
};

class CreditService;
class WeChatService;
class AlipayService;

class PaymentService 
{
public:
    void Payment(PaymentType paymentType, size_t amount)
    {
        if (PaymentType::CREDIT == paymentType) {
            creditService.payment();
        } else if (PaymentType::WECHAT == paymentType) {
            weChatService.payment();
        } else if (PaymentType::ALIPAY == paymentType) {
            alipayService.payment();
        }
    }

private:
    CreditService creditService;
    WeChatService weChatService;
    AlipayService alipayService;   
}
```
这种实现方法有以下缺点：
1. 不符合开闭原则，每增加一种支付方式，PaymentService 类都需要增加一个支付对象，并且还需要修改 Payment() 函数;
2. 不符合依赖倒置原则，依赖具体实现而不是依赖接口

### 2.2 使用策略模式
@@startuml
interface PaymentStrategy
{
    + Payment(): void
}
class CreditPaymentStrategy implements PaymentStrategy
class WechatPaymentStrategy implements PaymentStrategy
class AlipayPaymentStrategy implements PaymentStrategy

class PaymentService
{
    + Payment(paymentStrategy, amount): void
}
PaymentService ..> PaymentStrategy
@@enduml
有以下优点：
1. 符合开闭原则，每增加一种支付方式，只需要增加一个类实现 PaymentStrategy 接口，而不必修改原有代码，扩展性良好；
2. 符合依赖倒置原则
PS：这里其实就是使用继承多态的方式取代 if-else 判断