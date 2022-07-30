package com.wxy.dao;

import com.wxy.query.UserQuery;
import com.wxy.vo.User;
import org.apache.ibatis.session.SqlSession;
import org.apache.ibatis.session.SqlSessionFactory;

import java.util.List;

public class UserDaoImpl implements IUserDao {
    private SqlSessionFactory factory;

    public UserDaoImpl(SqlSessionFactory factory) {
        this.factory = factory;
    }

    @Override
    public User queryUserByName(String userName) {
        SqlSession session = factory.openSession();
        // mapper的namespace + 语句id
        User user = session.selectOne("com.wxy.mapper.UserMapper.queryUserByUserName", userName);
//        System.out.println(user);
        session.close();
        return user;
    }

    @Override
    public User queryUserByNameAndPwd(UserQuery userQuery) {
        // session不能作为局部变量共享，一个线程操作一个
        SqlSession session = factory.openSession();
        // mapper的namespace + 语句id
        User user = session.selectOne("com.wxy.mapper.UserMapper.queryUserByUserNameAndPwd", userQuery);
        session.close();
        return user;
    }

    @Override
    public List<User> queryUserByNameLike(String userName) {
        // session不能作为局部变量共享，一个线程操作一个
        SqlSession session = factory.openSession();
        List<User> users = session.selectList("com.wxy.mapper.UserMapper.queryUserByUserNameLike", userName);
        session.close();
        return users;
    }

    @Override
    public int insertUser(User user) {
        SqlSession session = factory.openSession(true);
        session.insert("com.wxy.mapper.UserMapper.insertUser", user);
        session.close();
        return user.getId();
    }

    @Override
    public int insertUserBatch(List<User> users) {
        SqlSession session = factory.openSession(true);
        int res = session.insert("com.wxy.mapper.UserMapper.insertUserBatch", users);
        session.close();
        return res;
    }
}
