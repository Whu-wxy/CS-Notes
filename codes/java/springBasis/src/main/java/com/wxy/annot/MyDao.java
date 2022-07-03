package com.wxy.annot;

import org.springframework.stereotype.Component;

//@Component(value = "md")
@Component
public class MyDao {
    public void test() {
        System.out.println("MyDao");
    }
}
