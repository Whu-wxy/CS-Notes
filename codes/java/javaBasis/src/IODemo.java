import java.io.*;

public class IODemo {
//    public static void main(String[] args) {
//        FileReader reader = null;
//        FileWriter writer = null;
//        char[] str = new char[50];
//        try {    // 注意抛出异常，放到try里
//            reader = new FileReader("./file.txt");
//            reader.read(str);
//        }
//        catch (Exception ex) {
//            System.out.println(ex.toString());
//        }
//        finally {
//            try {
//                reader.close();  // close方法抛出IO异常，要放到try catch
//            }
//            catch (Exception ex) {
//                System.out.println(ex.toString());
//            }
//        }
//
//    }

    public static void main(String[] args) throws IOException   {
        File file = new File("./file.txt");
        file.createNewFile();

        FileReader reader = new FileReader(file);
        FileWriter writer = new FileWriter(file, false);
        char[] str = new char[]{'1', '2', '3', '4'};
        char[] str2 = new char[50];

        writer.write("hello");
        writer.flush();
        writer.write(str);
        writer.close();

        int num = reader.read(str2);
//        for(char c: str2)
//        System.out.print(c);
        for(int i=0; i<num; i++)
            System.out.print(str2[i]);
        reader.close();  // close方法抛出IO异常，要放到try catch
    }
}
