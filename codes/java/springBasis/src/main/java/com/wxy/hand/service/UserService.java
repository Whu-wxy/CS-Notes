package com.wxy.hand.service;

import com.wxy.hand.dao.UserDao;

public class UserService {

    private UserDao userDao;

    private String userName;

    public void setUserDao(UserDao userDao) {
        this.userDao = userDao;
    }

    public void setUserName(String userName) {
        this.userName = userName;
    }

    public void test(){
        System.out.println("用户名："+userName);
    }
}
