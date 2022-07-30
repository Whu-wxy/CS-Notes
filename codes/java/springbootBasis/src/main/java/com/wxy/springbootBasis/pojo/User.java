package com.wxy.springbootBasis.pojo;

import java.util.Date;

import lombok.Data;

@Data
public class User {
	private int    id;
	private String userName;
	private String userPwd;
	private String flag;
	private Date   createTime;

	// 若不重写，输出为 com.wxy.vo.User@63f259c3
//	@Override
//	public String toString() {
//		return "User{" + "id=" + id + ", userName='" + userName + '\'' + ", userPwd='" + userPwd + '\'' + ", flag='"
//				+ flag + '\'' + ", createTime=" + createTime + '}';
//	}

}
