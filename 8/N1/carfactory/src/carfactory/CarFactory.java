package carfactory;
import carfactory.Car.BMW;
import carfactory.Car.Car;
import carfactory.Car.Tesla;
import carfactory.Car.Toyota;

public class CarFactory {
    public Car getCar (String continent) {
        if (continent.equalsIgnoreCase("Asia")) return (new Toyota());
        else if (continent.equalsIgnoreCase("Europe")) return (new BMW());
        else if (continent.equalsIgnoreCase("America")) return (new Tesla());
        return null;
    }
}
