package tong.Coffee;

public abstract class Coffee {
    String name = "Unknown Coffee";
    String title = "Unknown Coffee";
    String desc = "";

    // public Coffee() {
    //     desc += (name + " — " + cost());
    // }

    public void setTitle (String title) {
        this.title = title;
    }

    public String getTitle() {
        return this.title;
    }

    public String getName() {
        return name;
    }

    public String getDesc() {
        return desc;
    }

    public abstract double cost();
}
