package shakebuilder.Component;

public class Candy implements Component {
    @Override
    public String name() {
        return "Candy";
    }
    @Override
    public int price() {
        return 50;
    }
}
