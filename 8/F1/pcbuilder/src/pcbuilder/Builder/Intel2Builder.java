package pcbuilder.Builder;
import pcbuilder.Component.HardDisk;
import pcbuilder.Component.Motherboard;
import pcbuilder.Component.Cooler.LiquidCooler;
import pcbuilder.Component.Processor.IntelCi7;
import pcbuilder.Computer.*;

public class Intel2Builder extends IBuilder {

    private Computer pc = super.pc;

    public void addBaseComponents() {
        pc.setBasePrice(70000);
        pc.addBaseComponent(new HardDisk());
        pc.addBaseComponent(new Motherboard());
    }

    public void addBundledComponents() {
        pc.addBundledComponent(new IntelCi7());
        pc.addBundledComponent(new LiquidCooler());
        pc.setName("Intel Core-i7 11th Gen PC");
    }

    public Computer getComputer() {
        return pc;
    }  
}
