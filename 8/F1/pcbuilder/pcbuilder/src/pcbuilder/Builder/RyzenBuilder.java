package pcbuilder.Builder;
import pcbuilder.Component.HardDisk;
import pcbuilder.Component.Motherboard;
import pcbuilder.Component.Processor.Ryzen7;
import pcbuilder.Computer.*;

public class RyzenBuilder extends IBuilder {

    private Computer pc = super.pc;

    public void addBaseComponents() {
        pc.setBasePrice(70000);
        pc.addBaseComponent(new HardDisk());
        pc.addBaseComponent(new Motherboard());
    }

    public void addBundledComponents() {
        pc.addBundledComponent(new Ryzen7());
        pc.setName("AMD Ryzen 7 5700X Gaming PC");
    }

    public Computer getComputer() {
        return pc;
    }  
}
