package shakebuilder.Component;

public class Cookies implements Component {
    @Override
    public String name() {
        return "Cookies";
    }
    @Override
    public int price() {
        return 40;
    }
}
