package carfactory.Car;
import carfactory.Engine.*;
import carfactory.Color.*;
import carfactory.DriveTrain.*;
import carfactory.Country.*;


public class Tesla extends Car {
    @Override
    public String getModel() {
        return "Tesla";
    }
    @Override
    public Engine getEngine() {
        return (new ElectricEngine());
    }
    @Override
    public Color getColor() {
        return (new White());
    };
    @Override
    public DriveTrain getDriveTrain() {
        return (new AllWheel());
    };
    @Override
    public Country getCountry() {
        return (new USA());
    }
}
