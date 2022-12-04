package carfactory.Car;
import carfactory.Engine.*;
import carfactory.Color.*;
import carfactory.DriveTrain.*;
import carfactory.Country.*;


public class BMW extends Car {
    @Override
    public String getModel() {
        return "BMW";
    }
    @Override
    public Engine getEngine() {
        return (new ElectricEngine());
    }
    @Override
    public Color getColor() {
        return (new Black());
    };
    @Override
    public DriveTrain getDriveTrain() {
        return (new RearWheel());
    };
    @Override
    public Country getCountry() {
        return (new Germany());
    }
}
