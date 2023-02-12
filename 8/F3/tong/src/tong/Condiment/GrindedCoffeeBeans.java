package tong.Condiment;

import tong.Coffee.Coffee;

public class GrindedCoffeeBeans extends CondimentDecorator {

    public GrindedCoffeeBeans (Coffee coffee) {
        setCoffee(coffee);
    } 

    public String getName() {
        return "Grinded Coffee Beans";
    }

    public double cost() {
        return 30 + coffee.cost();
    }
}
