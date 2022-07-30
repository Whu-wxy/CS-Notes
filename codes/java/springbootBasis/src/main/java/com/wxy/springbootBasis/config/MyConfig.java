package com.wxy.springbootBasis.config;

import java.util.ArrayList;
import java.util.Date;
import java.util.List;

import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;

import com.wxy.springbootBasis.pojo.Person;

/**
 * 
 * @author 街道口扛把子 proxyBeanMethods = true return的是单例（默认）false为原型模式
 */
@Configuration(proxyBeanMethods = true)
public class MyConfig {

//	public Person getUser() {
//		List<Object> list = new ArrayList<Object>();
//		list.add("1");
//		list.add("2");
//		list.add(3);
//		return new Person("a person", new Date(), 2, list);
//	}

	@Bean("man")
	public Person getUser2() {
		List<Object> list = new ArrayList<Object>();
		list.add("1");
		list.add("2");
		list.add(3);
		return new Person("man", new Date(), 22, list);
	}
}
