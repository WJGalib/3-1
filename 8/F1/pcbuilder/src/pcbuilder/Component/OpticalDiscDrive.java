package pcbuilder.Component;

public class OpticalDiscDrive implements Component {
    @Override
    public String name() {
        return "DVD Player";
    }
    @Override
    public int price() {
        return 6000;
    }
}
