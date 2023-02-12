package tong.Condiment;

import tong.Coffee.Coffee;

public class DairyCream extends CondimentDecorator {

    public DairyCream (Coffee coffee) {
        setCoffee(coffee);
    } 

    public String getName() {
        return "Dairy Cream";
    }

    public double cost() {
        return 40 + coffee.cost();
    }
}
