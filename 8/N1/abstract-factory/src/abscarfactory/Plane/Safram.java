package abscarfactory.Plane;
import abscarfactory.Engine.*;


public class Safram extends Plane {
    @Override
    public String getModel() {
        return "Safram";
    }
    @Override
    public Engine getEngine() {
        return (new SaframEngine());
    }
}
