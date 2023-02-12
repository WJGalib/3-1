package tong.Condiment;

import tong.Coffee.Coffee;

public class CinnamonPowder extends CondimentDecorator {

    public CinnamonPowder (Coffee coffee) {
        setCoffee(coffee);    } 

    public String getName() {
        return "Cinnamon Powder";
    }

    public double cost() {
        return 50 + coffee.cost();
    }
}
