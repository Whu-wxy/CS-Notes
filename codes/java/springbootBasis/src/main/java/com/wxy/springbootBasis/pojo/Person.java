package com.wxy.springbootBasis.pojo;

import java.util.Date;
import java.util.List;

import org.springframework.boot.context.properties.ConfigurationProperties;
import org.springframework.stereotype.Component;

import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

@Component
@Data
@ConfigurationProperties(prefix = "person")
@AllArgsConstructor
@NoArgsConstructor
public class Person {
	private String       name;
	private Date         birth;
	private int          age;
	private List<Object> list;

}
