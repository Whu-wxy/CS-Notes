package com.wxy.springbootBasis.controller;

import org.springframework.boot.context.properties.ConfigurationProperties;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.ResponseBody;


//  http://localhost:8081/hello/hello
@Controller
@RequestMapping("/hello")
@ConfigurationProperties(prefix = "hello")
public class HelloController {

    @GetMapping("/hello")
    @ResponseBody
    public String hello(){
        return "hello.";
    }

}
