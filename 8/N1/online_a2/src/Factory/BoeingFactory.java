package Factory;

import Engine.*;
import Factory.PlaneFactory;
import Wing.*;

public class BoeingFactory implements PlaneFactory {
    @Override
    public String getCompany() {
        return "Boeing";
    }

    @Override
    public Engine getEngine() {
        return new BoeingEngine();
    }

    @Override
    public Wing getWing() {
        return new BoeingWing();
    }
}
