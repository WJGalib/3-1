package pcbuilder.Builder;
import pcbuilder.Component.HardDisk;
import pcbuilder.Component.Motherboard;
import pcbuilder.Component.Cooler.CpuCooler;
import pcbuilder.Component.Processor.IntelCi5;
import pcbuilder.Computer.*;

public class Intel1Builder extends IBuilder {

    private Computer pc = super.pc;

    public void addBaseComponents() {
        pc.setBasePrice(70000);
        pc.addBaseComponent(new HardDisk());
        pc.addBaseComponent(new Motherboard());
    }

    public void addBundledComponents() {
        pc.addBundledComponent(new IntelCi5());
        pc.addBundledComponent(new CpuCooler());
        pc.setName("Intel Core-i5 11th Gen PC");
    }

    public Computer getComputer() {
        return pc;
    }  
}
