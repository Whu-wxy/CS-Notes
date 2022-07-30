package com.wxy.springbootBasis;

import org.mybatis.spring.annotation.MapperScan;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.context.ConfigurableApplicationContext;

import com.wxy.springbootBasis.config.MyConfig;
import com.wxy.springbootBasis.pojo.Person;

@SpringBootApplication
@MapperScan({ "com.wxy.springbootBasis.mapper" })
public class SpringbootBasisApplication {

	public static void main(String[] args) {
		// 返回IOC容器，包含所有组件
		ConfigurableApplicationContext run = SpringApplication.run(SpringbootBasisApplication.class, args);

		// 查看所有组件
//		String[] nameStrings = run.getBeanDefinitionNames();
//		for (String string : nameStrings) {
//			System.out.println(string);
//		}

		Person person = run.getBean("man", Person.class);
		Person person2 = run.getBean("man", Person.class);

		System.out.println("组件：" + (person.equals(person2)));

		MyConfig config = run.getBean(MyConfig.class);
		System.out.println(config);
	}

}
