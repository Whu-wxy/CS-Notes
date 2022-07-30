package com.wxy.dao;

import com.wxy.query.UserQuery;
import com.wxy.vo.User;

import java.util.List;

public interface IUserDao {
    public User queryUserByName(String userName);

    public User queryUserByNameAndPwd(UserQuery userQuery);

    public List<User> queryUserByNameLike(String userName);

    public int insertUser(User user);

    public int insertUserBatch(List<User> users);

}
