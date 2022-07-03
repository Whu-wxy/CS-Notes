package com.wxy.hand.po.proxy;

import org.aspectj.lang.ProceedingJoinPoint;
import org.aspectj.lang.annotation.*;
import org.springframework.stereotype.Component;

/**
 * 定义切面类
 *    切入点
 *    通知
 */
@Component
@Aspect
public class LogAspect {

    /**
     *  定义切入点
     *  execution: 执行匹配
     *  * com.wxy.ssm.service..*.*(..))
     *  * 匹配public/protected/private修饰的方法
     *  com.wxy.ssm.service针对这个包
     *  ..* 子包中所有的类
     *  .* 这个包下所有的类   *可用具体的值
     *  (..) 表示参数列表
     */
    @Pointcut("execution(* com.wxy.hand.service..*.*(..))")
    public void cut(){

    }

    /**
     *  定义前置通知
     */
    @Before(value = "cut()")
    public void before(){
        System.out.println("前置通知.");
    }

    /**
     *  后置通知
     *      在目标方法return后执行，中间出现异常不执行
     */
    @AfterReturning(value = "cut()")
    public void afterReturn(){
        System.out.println("后置通知.");
    }

    /**
     *  最终通知
     *    目标方法无论是否出现异常，最终都会执行
     */
    @After(value = "cut()")
    public void after(){

    }

    /**
     * 环绕通知，可代替前面的
     */
    @Around(value = "cut()")
    public Object around(ProceedingJoinPoint pjp) throws Throwable{
        Object result = null;

        System.out.println("环绕方法，开始.");
        // 执行pjp目标对象方法
        result = pjp.proceed();
        System.out.println("环绕方法，结束.");

        return result;
    }
}
