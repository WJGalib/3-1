package carfactory.Car;
import carfactory.Engine.*;
import carfactory.Color.*;
import carfactory.DriveTrain.*;
import carfactory.Country.*;


public class Toyota extends Car {
    @Override
    public String getModel() {
        return "Toyota";
    }
    @Override
    public Engine getEngine() {
        return (new HydrogenFuelCell());
    }
    @Override
    public Color getColor() {
        return (new Red());
    };
    @Override
    public DriveTrain getDriveTrain() {
        return (new RearWheel());
    };
    @Override
    public Country getCountry() {
        return (new Japan());
    }
}
