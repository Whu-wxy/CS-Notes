package com.wxy.springcloud.controller;

import com.wxy.springcloud.entities.CommonResult;
import com.wxy.springcloud.entities.Payment;
import com.wxy.springcloud.service.PaymentService;
import lombok.extern.slf4j.Slf4j;
import org.springframework.web.bind.annotation.*;

import javax.annotation.Resource;

@RestController
@Slf4j
public class PaymentController {
    @Resource
    private PaymentService paymentService;

    @PostMapping("/payment/create")
    public CommonResult createPayment(@RequestBody Payment payment){
        int result = paymentService.createPayment(payment);
        log.info("插入结果：" + result);

        if(result > 0){
            return new CommonResult(200, "插入数据库成功", result);
        } else {
            return new CommonResult(444, "插入数据库失败", null);
        }
    }

    @GetMapping("/payment/get/{id}")
    public CommonResult getPaymentById(@PathVariable("id") Long id) {
        Payment result = paymentService.getPaymentById(id);
        log.info("查询结果：" + result);

        if(result != null){
            return new CommonResult(200, "查询成功", result);
        } else {
            return new CommonResult(444, "没有对应记录，查询id: "+id, null);
        }
    }
}
