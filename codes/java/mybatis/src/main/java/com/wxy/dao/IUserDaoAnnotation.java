package com.wxy.dao;

import org.apache.ibatis.annotations.Delete;
import org.apache.ibatis.annotations.Insert;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Select;

import com.wxy.vo.User;

@Mapper
public interface IUserDaoAnnotation {

	// 可以用注解写一些简单的sql，容易写错，复杂的还是到xml中
	// 注解方式不用实现类，可以直接用
	// 注意select不支持多条件，多条件用SelectProvider
	// 返回影响的记录数，想要返回主键，在xml中设置属性
	@Select("select id, user_name as userName, user_pwd as userPwd, flag, create_time as createTime "
			+ " from user where id = #{id}")
	public User queryUserById(int id);

	@Insert("insert into user(id, user_name, user_pwd, flag, create_time) "
			+ " values(#{id}, #{userName}, #{userPwd}, #{flag}, #{createTime})")
	public int addUser(User user);

	@Delete("delete from user where id=#{id}")
	public int deleteUserById(int id);
}
