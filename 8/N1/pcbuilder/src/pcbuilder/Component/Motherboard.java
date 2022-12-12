package pcbuilder.Component;

public class Motherboard implements Component {
    @Override
    public String name() {
        return "Motherboard";
    }
    @Override
    public int price() {
        return 0;
    }
}
