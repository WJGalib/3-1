package Factory;

import Engine.Engine;
import Wing.Wing;

public interface PlaneFactory {
     String getCompany();
     Engine getEngine();
     Wing getWing();
}
