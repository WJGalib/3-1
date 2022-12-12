package abscarfactory;
import abscarfactory.Engine.Engine;
import abscarfactory.Plane.Plane;


public abstract class PlaneFactory {
    public abstract Plane getPlane (String company);
    public abstract Engine getEngine (String company);
}
