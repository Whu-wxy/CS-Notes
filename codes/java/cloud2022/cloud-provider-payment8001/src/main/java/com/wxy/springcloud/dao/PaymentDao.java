package com.wxy.springcloud.dao;

import com.wxy.springcloud.entities.Payment;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Param;
import org.springframework.stereotype.Repository;

@Mapper
public interface PaymentDao {

    public int createPayment(Payment payment);

    public Payment getPaymentById(@Param("id") Long id);
}
