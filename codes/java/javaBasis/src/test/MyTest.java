package test;

import ThreadDemo.ThreadDemo;
import org.junit.Test;

public class MyTest {

    public void test1(){
        ThreadDemo R1 = new ThreadDemo("Thread-1");
        R1.start();

        ThreadDemo R2 = new ThreadDemo("Thread-2");
        R2.start();
    }
}
