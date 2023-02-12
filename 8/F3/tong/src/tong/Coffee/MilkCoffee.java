package tong.Coffee;

public class MilkCoffee extends Coffee {
    public MilkCoffee() {
        name = "Milk Coffee";
        title = name;
        desc += ("Mug" + " — " + 100.0 + " taka\n");
        desc += ("Grinded Coffee Beans" + " — " + 30.0 + " taka\n");
        desc += ("Milk" + " — " + 50.0 + " taka\n");
    }

    public double cost() {
        return 180;
    }
}
