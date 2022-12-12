package abscarfactory.PlaneFactory;
import abscarfactory.Engine.AirbusEngine;
import abscarfactory.Engine.Engine;
import abscarfactory.Plane.Airbus;
import abscarfactory.Plane.Plane;


public class AirbusFactory extends PlaneFactory {
    public Plane getPlane (String company) {
        return (new Airbus());
    }
    public Engine getEngine (String company) {
        return (new AirbusEngine());
    }
}
