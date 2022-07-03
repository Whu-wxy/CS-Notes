package com.wxy.annot.service;

import com.wxy.annot.dao.UserDao;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Qualifier;
import org.springframework.stereotype.Service;

@Service
public class UserService {
    /**
     *   用注解代替set+xml的property
     *   Autowired + Qualifier(value = "userDao") = Resource(name = "userDao")
     */
//    @Resource
//    @Resource(name = "userDao")
    @Autowired
    @Qualifier(value = "userDao")
    private UserDao userDao;  //名称要和xml中UserDao的id一致

    public void setUserDao(UserDao userDao) {
        this.userDao = userDao;
    }

    public void test() {
        System.out.println("component-scan auto UserService");
        userDao.test();
    }
}
