package tong.Condiment;

import tong.Coffee.Coffee;

public class Milk extends CondimentDecorator {
    public Milk (Coffee coffee) {
        setCoffee(coffee);
    } 

    public String getName() {
        return "Milk";
    }

    public double cost() {
        return 50 + coffee.cost();
    }
}
