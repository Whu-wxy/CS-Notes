package com.wxy;

import com.wxy.dao.IUserDao;
import com.wxy.dao.UserDaoImpl;
import com.wxy.query.UserQuery;
import com.wxy.vo.User;
import org.apache.ibatis.io.Resources;
import org.apache.ibatis.session.SqlSessionFactory;
import org.apache.ibatis.session.SqlSessionFactoryBuilder;
import org.junit.Before;
import org.junit.Test;

import java.io.IOException;
import java.io.InputStream;
import java.io.Reader;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;

public class TestUserDao {
    private IUserDao userDao;

    @Before
    public void before(){
        try {
//            InputStream is = Resources.getResourceAsStream("mybatis.xml");
            Reader resourceAsReader = Resources.getResourceAsReader("mybatis.xml");

//            SqlSessionFactory factory = new SqlSessionFactoryBuilder().build(is);
            SqlSessionFactory factory = new SqlSessionFactoryBuilder().build(resourceAsReader);
            userDao = new UserDaoImpl(factory);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    @Test
    public void test() {
        System.out.println(userDao.queryUserByName("wxy"));
    }

    @Test
    public void test2() {
        UserQuery query = new UserQuery();
        query.setUserName("wxy");
        query.setUserPwd("123");
        System.out.println(userDao.queryUserByNameAndPwd(query));
    }

    @Test
    public void test3() {
        userDao.queryUserByNameLike("wxy").forEach((u) -> {
                System.out.println(u);
        });
    }

    @Test
    public void test4() {
        User user = new User();
//        user.setId(11);
        user.setCreateTime(new Date());
        user.setFlag("0");
        user.setUserName("test2");
        user.setUserPwd("test2");
        System.out.println(userDao.insertUser(user));
    }

    @Test
    public void test5() {
        List<User> users = new ArrayList<User>();

        for (int i=0; i<10; i++) {
            User user = new User();
            user.setFlag("0");
            user.setUserName("wxy" + (i+1));
            user.setUserPwd("test");
            user.setCreateTime(new Date());
            users.add(user);
        }
        System.out.println(userDao.insertUserBatch(users));
    }
}
