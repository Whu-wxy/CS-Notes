package com.wxy.springbootBasis.controller;

import java.util.List;

import javax.annotation.Resource;

import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RestController;

import com.fasterxml.jackson.core.JsonProcessingException;
import com.fasterxml.jackson.databind.ObjectMapper;
import com.wxy.springbootBasis.mapper.UserMapper;
import com.wxy.springbootBasis.pojo.User;

@RestController
public class UserController {

	@Resource
	private UserMapper userMapper;

	@GetMapping("/usernamelike/{name}")
	public String queryUserByNameLike(@PathVariable String name) throws JsonProcessingException {
		List<User> users = userMapper.queryUserByNameLike(name);
		ObjectMapper mapper = new ObjectMapper();
		return mapper.writeValueAsString(users);
	}

	@GetMapping("/userid/{id}")
	public String queryUserById(@PathVariable int id) throws JsonProcessingException {
		User user = userMapper.queryUserById(id);
		System.out.println(user);
		ObjectMapper mapper = new ObjectMapper();
		String reString = mapper.writeValueAsString(user);
		return reString;
	}

}
