package abscarfactory.PlaneFactory;
import abscarfactory.Engine.Engine;
import abscarfactory.Engine.SaframEngine;
import abscarfactory.Plane.Plane;
import abscarfactory.Plane.Safram;


public class SaframFactory extends PlaneFactory {
    public Plane getPlane (String company) {
        return (new Safram());
    }
    public Engine getEngine (String company) {
        return (new SaframEngine());
    }
}
