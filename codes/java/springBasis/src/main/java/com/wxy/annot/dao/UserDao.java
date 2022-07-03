package com.wxy.annot.dao;

import org.springframework.stereotype.Repository;

@Repository
public class UserDao {
    public void test() {
        System.out.println("component-scan auto userDao");
    }
}
