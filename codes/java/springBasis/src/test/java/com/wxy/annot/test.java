package com.wxy.annot;

import com.wxy.annot.service.UserService;
import com.wxy.annot.dao.UserDao;

import org.junit.Test;
import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

public class test {
    @Test
    public void test(){
        ApplicationContext ac = new ClassPathXmlApplicationContext("spring-annotation.xml");
        // id遵从：不指定bean的名称，默认为类名首字母小写其它不变，之后赋给id
        UserService userService = (UserService) ac.getBean("userService"); // 注意getBean里的名字
//        UserService userService = (UserService) ac.getBean(UserService.class);
        System.out.println(UserService.class);
        userService.test();
    }

    @Test
    public void test2(){
        ApplicationContext ac = new ClassPathXmlApplicationContext("spring-annotation.xml");
        UserDao ud = (UserDao) ac.getBean("userDao");
//        UserDao ud = (UserDao) ac.getBean("UserDao");
        ud.test();
    }

    @Test
    public void test3(){
        ApplicationContext ac = new ClassPathXmlApplicationContext("spring-annotation.xml");
        ABCdEFg aaa = (ABCdEFg) ac.getBean("ABCdEFg"); //yes
//        ABCdEFg aaa = (ABCdEFg) ac.getBean("aBCdEFg"); //no
        aaa.test();
    }

    @Test
    public void test4(){
        ApplicationContext ac = new ClassPathXmlApplicationContext("spring-annotation.xml");
        MyDao aaa = (MyDao) ac.getBean("myDao"); //yes
//        MyDao aaa = (MyDao) ac.getBean("MyDao"); //no
        aaa.test();
    }
}
