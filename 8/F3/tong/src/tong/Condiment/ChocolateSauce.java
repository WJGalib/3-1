package tong.Condiment;

import tong.Coffee.Coffee;

public class ChocolateSauce extends CondimentDecorator {

    public ChocolateSauce (Coffee coffee) {
        setCoffee(coffee);
    } 

    public String getName() {
        return "Chocolate Sauce";
    }

    public double cost() {
        return 60 + coffee.cost();
    }
}
