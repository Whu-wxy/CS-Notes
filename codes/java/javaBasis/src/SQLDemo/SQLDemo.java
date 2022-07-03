package SQLDemo;

public class SQLDemo {
    public static void main(String[] args) {
        SQLiteJDBC db = new SQLiteJDBC();
        db.open();
        db.create();
        db.insert();
        db.select();

        db.close();



    }
}
