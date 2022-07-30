package com.wxy;

import java.io.IOException;
import java.io.InputStream;
import java.io.Reader;
import java.util.Date;

import org.apache.ibatis.io.Resources;
import org.apache.ibatis.session.SqlSession;
import org.apache.ibatis.session.SqlSessionFactory;
import org.apache.ibatis.session.SqlSessionFactoryBuilder;
import org.junit.Test;

import com.wxy.dao.IUserDaoAnnotation;
import com.wxy.vo.User;

public class AppTest {

	@Test
	public void test() {
		/**
		 * 读取配置文件 加载配置文件创建SqlSessionFactory 创建Session 通过Session操作数据库 处理结果 关闭Session
		 */
		try {
			InputStream is = Resources.getResourceAsStream("mybatis.xml");
			Reader resourceAsReader = Resources.getResourceAsReader("mybatis.xml");

//            SqlSessionFactory factory = new SqlSessionFactoryBuilder().build(is);
			SqlSessionFactory factory = new SqlSessionFactoryBuilder().build(resourceAsReader);

			SqlSession session = factory.openSession();
			// mapper的namespace + 语句id
			User user = session.selectOne("com.wxy.mapper.UserMapper.queryUserById", 4);
			System.out.println(user);
			session.close();
			// xml文件放到代码目录下，maven不会编译并拿到target输出目录，resources目录中的会
			// 解决：在pom.xml的build中，显示配置resources标签
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	@Test
	public void test2() {
		/**
		 * 读取配置文件 加载配置文件创建SqlSessionFactory 创建Session 通过Session操作数据库 处理结果 关闭Session
		 */
		try {
			InputStream is = Resources.getResourceAsStream("mybatis.xml");
			Reader resourceAsReader = Resources.getResourceAsReader("mybatis.xml");

//            SqlSessionFactory factory = new SqlSessionFactoryBuilder().build(is);
			SqlSessionFactory factory = new SqlSessionFactoryBuilder().build(resourceAsReader);

			SqlSession session = factory.openSession();
			// mapper的namespace + 语句id
			User user = session.selectOne("com.wxy.mapper.UserMapper.queryUserByUserName", "wxy");
			System.out.println(user);
			session.close();
			// xml文件放到代码目录下，maven不会编译并拿到target输出目录，resources目录中的会
			// 解决：在pom.xml的build中，显示配置resources标签
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	// ////////////////////注解方式///////////////////////
	@Test
	public void test3() {
		try {
			InputStream is = Resources.getResourceAsStream("mybatis.xml");
			Reader resourceAsReader = Resources.getResourceAsReader("mybatis.xml");

			// SqlSessionFactory factory = new SqlSessionFactoryBuilder().build(is);
			SqlSessionFactory factory = new SqlSessionFactoryBuilder().build(resourceAsReader);

			SqlSession session = factory.openSession();

			// 注解方式的区别
			IUserDaoAnnotation userDaoAnnotationProxy = session.getMapper(IUserDaoAnnotation.class);
			User user = userDaoAnnotationProxy.queryUserById(4);
			// 注解方式的区别

			System.out.println(user);
			session.close();
			// xml文件放到代码目录下，maven不会编译并拿到target输出目录，resources目录中的会
			// 解决：在pom.xml的build中，显示配置resources标签
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	@Test
	public void test4() {
		try {
			InputStream is = Resources.getResourceAsStream("mybatis.xml");
			Reader resourceAsReader = Resources.getResourceAsReader("mybatis.xml");

//            SqlSessionFactory factory = new SqlSessionFactoryBuilder().build(is);
			SqlSessionFactory factory = new SqlSessionFactoryBuilder().build(resourceAsReader);

			// true: autoCommit
			SqlSession session = factory.openSession(true);

			// 注解方式的区别
			User user = new User();
			user.setId(10);
			user.setUserName("zfy");
			user.setFlag("1");
			user.setUserPwd("666");
			user.setCreateTime(new Date());
			IUserDaoAnnotation userDaoAnnotationProxy = session.getMapper(IUserDaoAnnotation.class);
			userDaoAnnotationProxy.addUser(user);
			// 注解方式的区别

			session.close();
			// xml文件放到代码目录下，maven不会编译并拿到target输出目录，resources目录中的会
			// 解决：在pom.xml的build中，显示配置resources标签
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	@Test
	public void test5() {
		try {
			InputStream is = Resources.getResourceAsStream("mybatis.xml");
			Reader resourceAsReader = Resources.getResourceAsReader("mybatis.xml");

//            SqlSessionFactory factory = new SqlSessionFactoryBuilder().build(is);
			SqlSessionFactory factory = new SqlSessionFactoryBuilder().build(resourceAsReader);

			// true: autoCommit
			SqlSession session = factory.openSession(true);

			// 注解方式的区别
			IUserDaoAnnotation userDaoAnnotationProxy = session.getMapper(IUserDaoAnnotation.class);
			userDaoAnnotationProxy.deleteUserById(10);
			// 注解方式的区别

			session.close();
			// xml文件放到代码目录下，maven不会编译并拿到target输出目录，resources目录中的会
			// 解决：在pom.xml的build中，显示配置resources标签
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}
