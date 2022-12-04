package pcbuilder.Component.GraphicsCard;
import pcbuilder.Component.*;

public abstract class GraphicsCard implements Component {
    protected abstract int capacity();
    public abstract int price();
    public String name() {
        return capacity() + " GB Graphics Card";
    }
}
