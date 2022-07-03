package com.wxy.hand;

import com.wxy.hand.service.*;

import static org.junit.Assert.assertTrue;

import org.junit.Test;
import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

/**
 * Unit test for simple App.
 */
public class test
{
    /**
     * Rigorous Test :-)
     */
    @Test
    public void test() {
        ApplicationContext ac = new ClassPathXmlApplicationContext("spring.xml");
        FirstSpring fs = (FirstSpring) ac.getBean("FirstSpring");
        fs.test();
    }

    @Test
    public void test2() {
        ApplicationContext ac = new ClassPathXmlApplicationContext("spring.xml");
        UserService us = (UserService) ac.getBean("UserService");
        us.test();
    }
}
