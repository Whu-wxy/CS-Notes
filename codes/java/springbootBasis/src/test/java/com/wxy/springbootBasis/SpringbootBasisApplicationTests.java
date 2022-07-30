package com.wxy.springbootBasis;

import javax.annotation.Resource;

import org.junit.jupiter.api.Test;
import org.springframework.boot.context.properties.EnableConfigurationProperties;
import org.springframework.boot.test.context.SpringBootTest;

import com.wxy.springbootBasis.pojo.Person;

@SpringBootTest
@EnableConfigurationProperties(Person.class)
class SpringbootBasisApplicationTests {
	@Resource
	Person person = new Person();

	@Test
	void contextLoads() {
		System.out.println(person);
	}

}
