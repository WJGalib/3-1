package abscarfactory.Plane;
import abscarfactory.Engine.*;


public class Boeing extends Plane {
    @Override
    public String getModel() {
        return "Boeing";
    }
    @Override
    public Engine getEngine() {
        return (new BoeingEngine());
    }
}
