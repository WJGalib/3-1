package carfactory.Car;

import carfactory.Color.Color;
import carfactory.Country.Country;
import carfactory.DriveTrain.DriveTrain;
import carfactory.Engine.Engine;

public abstract class Car {
    public abstract String getModel();
    public abstract Engine getEngine();
    public abstract Color getColor();
    public abstract DriveTrain getDriveTrain();
    public abstract Country getCountry();
    public void print() {
        System.out.println("\n—————————————");
        System.out.println(getModel());
        System.out.println("—————————————");
        System.out.println("Engine Type: " + getEngine().getName());
        System.out.println("Colour: " + getColor().getName());
        System.out.println("Drive Train: " + getDriveTrain().getName());
        System.out.println("Country: " + getCountry().getName());
    }
}
