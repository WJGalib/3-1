package abscarfactory.Plane;
import abscarfactory.Engine.*;


public class Airbus extends Plane {
    @Override
    public String getModel() {
        return "Airbus";
    }
    @Override
    public Engine getEngine() {
        return (new AirbusEngine());
    }
}
