package com.wxy.controller;

import com.fasterxml.jackson.core.JsonProcessingException;
import com.fasterxml.jackson.databind.ObjectMapper;
import com.wxy.po.User;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.*;

@Controller
//@RequestMapping("/xxx")   使类中所有的都加上这个前缀
public class HelloController {

    // 表示访问地址
    @RequestMapping("/hello")
    public String hello(Model model){
        // 向模型中添加值，可在jsp中取出并渲染
        model.addAttribute("msg", "Hello SpringMVC.");
//        return "hello";  // 被视图解析器处理，即处理hello.jsp
        return "redirect:/index.jsp";  //重定向
    }

//    http://localhost:8081/SpringMVCBasis/add?a=1&b=2
//    @RequestMapping("/add")
//    public String add(@RequestParam("a") int a, int b, Model model){
//        int res = a + b;
//        // 向模型中添加值，可在jsp中取出并渲染
//        model.addAttribute("msg", "result = " + res);
//        return "hello";  // 被视图解析器处理，即处理hello.jsp
//    }


    // RestFul风格写法
    // method = RequestMethod.GET 设置类型
    @RequestMapping(value = "/add/{a}/{b}", method = RequestMethod.GET)
//    @GetMapping
//    @PostMapping
//    @DeleteMapping
    public String add(@PathVariable int a, @PathVariable int b, Model model){
        int res = a + b;
        // 向模型中添加值，可在jsp中取出并渲染
        model.addAttribute("msg", "result = " + res);
        return "hello";    // 被视图解析器处理，即处理hello.jsp
//        return "/WEB-INF/jsp/hello.jsp";
//        return "forward:/WEB-INF/jsp/hello.jsp";  //转发
    }

    @RequestMapping("/test")
    public String test(){             //不需要返回数据的话，可以不用Model
        return "redirect:/index.jsp";  //重定向
    }

//    @RequestMapping("/jsontest")
//    @RequestMapping(value = "/jsontest", produces = "application/json;charset=utf-8") // 返回乱码，设置返回json，以及编码格式
    @RequestMapping(value = "/jsontest")  // 在xml中设置编码
    @ResponseBody   // 不走视图解析器
    public String jsonTest() throws JsonProcessingException {
        User user = new User("方高方", 22, "男");

        ObjectMapper mapper = new ObjectMapper();
        return mapper.writeValueAsString(user);
//        return user.toString();
    }
}
