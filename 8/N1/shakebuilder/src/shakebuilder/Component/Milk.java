package shakebuilder.Component;

public abstract class Milk implements Component {
    @Override
    public String name() {
        return "Milk";
    }
    @Override
    public int price() {
        return 0;
    }
}
