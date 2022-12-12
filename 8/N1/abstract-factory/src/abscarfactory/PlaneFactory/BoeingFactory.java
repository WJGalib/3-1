package abscarfactory.PlaneFactory;
import abscarfactory.Engine.BoeingEngine;
import abscarfactory.Engine.Engine;
import abscarfactory.Plane.Boeing;
import abscarfactory.Plane.Plane;


public class BoeingFactory extends PlaneFactory {
    public Plane getPlane (String company) {
        return (new Boeing());
    }
    public Engine getEngine (String company) {
        return (new BoeingEngine());
    }
}
