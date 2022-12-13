package Factory;

import Engine.*;
import Wing.*;

public class SafranFactory implements PlaneFactory{
    @Override
    public String getCompany() {
        return "Safran";
    }

    @Override
    public Engine getEngine() {
        return new SafranEngine();
    }

    @Override
    public Wing getWing() {
        return new SafranWing();
    }
}
