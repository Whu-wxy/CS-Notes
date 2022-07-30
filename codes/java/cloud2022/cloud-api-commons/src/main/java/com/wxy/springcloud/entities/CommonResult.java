package com.wxy.springcloud.entities;

import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

@Data
@AllArgsConstructor
@NoArgsConstructor
public class CommonResult<T> {
    private int     code;
    private String  message;
    private T       data;

    public CommonResult(int code, String message){
        this(code, message, null);
    }
}
