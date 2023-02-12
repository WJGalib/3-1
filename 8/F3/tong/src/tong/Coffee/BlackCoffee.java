package tong.Coffee;

public class BlackCoffee extends Coffee {
    public BlackCoffee() {
        name = "Black Coffee";
        title = name;
        desc += ("Mug" + " — " + 100.0 + " taka\n");
        desc += ("Grinded Coffee Beans" + " — " + 30.0 + " taka\n");
        desc += ("Water" + " — " + 0.0 + " taka\n");
    }

    public double cost() {
        return 130;
    }
}
