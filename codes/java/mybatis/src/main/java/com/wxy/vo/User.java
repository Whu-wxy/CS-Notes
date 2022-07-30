package com.wxy.vo;

import java.util.Date;

public class User {
    private int id;
    private String userName;
    private String userPwd;
    private String flag;
    private Date createTime;

    // 若不重写，输出为 com.wxy.vo.User@63f259c3
    @Override
    public String toString() {
        return "User{" +
                "id=" + id +
                ", userName='" + userName + '\'' +
                ", userPwd='" + userPwd + '\'' +
                ", flag='" + flag + '\'' +
                ", createTime=" + createTime +
                '}';
    }

    public void setId(int id) {
        this.id = id;
    }

    public int getId() {
        return id;
    }

    public void setUserName(String userName) {
        this.userName = userName;
    }

    public void setUserPwd(String userPwd) {
        this.userPwd = userPwd;
    }

    public void setFlag(String flag) {
        this.flag = flag;
    }

    public void setCreateTime(Date createTime) {
        this.createTime = createTime;
    }
}
