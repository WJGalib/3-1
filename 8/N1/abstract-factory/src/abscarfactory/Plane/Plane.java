package abscarfactory.Plane;
import abscarfactory.Engine.Engine;

public abstract class Plane {
    public abstract String getModel();
    public abstract Engine getEngine();

    public void print() {
        System.out.println("\n—————————————");
        System.out.println(getModel());
        System.out.println("—————————————");
        System.out.println("Engine Type: " + getEngine().getName());
    }
}
