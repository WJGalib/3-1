package pcbuilder.Component.Memory;
import pcbuilder.Component.*;

public abstract class Memory implements Component {
    protected int capacity() {
        return 8; 
    };
    protected abstract int frequency();
    public abstract int price();
    public String name() {
        return capacity() + "GB DDR4 " + frequency() + " MHz RAM";
    }
}
