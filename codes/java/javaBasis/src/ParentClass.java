import java.util.Scanner;

public class ParentClass {
    private byte byteNum = 127;  // -128~127
    private static int intNum;
    protected long longNum = 1L;
    private float floatNum = 1.2F;
    private double doubleNum = 2.2;
    private static final boolean STATUS = false;
    private char charMember = '字';
    int[] myArray = new int[]{1,2,3,4,5};
    int[][] myArray2 = new int[][]{{1,2},{3,4}};

    private String str = "hello";
    private String str2 = new String();
    private String str3 = new String("world");

    public ParentClass() {

    }

    public ParentClass(int num) {
        this.intNum = num;
    }

    public String getName() {
        return "Parent";
    }

    static {
        intNum = 0;
    }

    public static void main(String[] args) {
        String s1 = "111";
        s1 = "222";
        s1 = "55555aaa";
        System.out.println(s1);

//        System.out.println("请输入密码：");
//        Scanner val = new Scanner(System.in);
//        int code = val.nextInt();
//        System.out.println("结果为：" + code);
//        val.close();
    }
}

class ChildClass extends ParentClass {

    public ChildClass(int num) {
        super(num);
        System.out.println(this.longNum);
    }

    @Override
    public String getName() {
        return "Child";
    }

}