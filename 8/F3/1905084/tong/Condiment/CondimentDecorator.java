package tong.Condiment;

import tong.Coffee.Coffee;

public abstract class CondimentDecorator extends Coffee {
    Coffee coffee;

    public Coffee getCoffee() {
        return this.coffee;
    }

    public void setCoffee (Coffee coffee) {
        this.coffee = coffee;
    }

    public String getDesc() {
        return coffee.getDesc() + getName() + " — " + (cost() - coffee.cost()) + " taka\n";
    }

    String desc = "";

    // public String getDesc() {
    //     return (getName() + " — " + cost());
    // }


    // public String getDesc() {
    //     return desc;
    // }

}
