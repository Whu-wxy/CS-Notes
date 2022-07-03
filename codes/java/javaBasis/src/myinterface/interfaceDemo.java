package myinterface;

public interface interfaceDemo {
    public static final int X = 6;
    public abstract int getResult();

    public default int getX() {
        return X;
    }
}

