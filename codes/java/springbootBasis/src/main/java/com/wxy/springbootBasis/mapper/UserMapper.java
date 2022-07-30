package com.wxy.springbootBasis.mapper;

import java.util.List;

import org.springframework.stereotype.Repository;

import com.wxy.springbootBasis.pojo.User;
import com.wxy.springbootBasis.query.UserQuery;

//@Mapper 或者 MapperScan
@Repository
public interface UserMapper {
	public User queryUserById(int id);

	public User queryUserByName(String userName);

	public User queryUserByNameAndPwd(UserQuery userQuery);

	public List<User> queryUserByNameLike(String userName);

	public int insertUser(User user);

	public int insertUserBatch(List<User> users);

}
