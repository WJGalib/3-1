package pcbuilder.Component;

public class HardDisk implements Component {
    protected int capacity() {
        return 1;
    }

    @Override
    public String name() {
        return capacity() + " TB Hard Disk";
    }
    @Override
    public int price() {
        return 0;
    }
}
