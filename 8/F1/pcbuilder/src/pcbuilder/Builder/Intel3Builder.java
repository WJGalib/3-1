package pcbuilder.Builder;
import pcbuilder.Component.HardDisk;
import pcbuilder.Component.Motherboard;
import pcbuilder.Component.OpticalDiscDrive;
import pcbuilder.Component.Processor.IntelCi9;
import pcbuilder.Computer.*;

public class Intel3Builder extends IBuilder {

    private Computer pc = super.pc;

    public void addBaseComponents() {
        pc.setBasePrice(70000);
        pc.addBaseComponent(new HardDisk());
        pc.addBaseComponent(new Motherboard());
    }

    public void addBundledComponents() {
        pc.addBundledComponent(new IntelCi9());
        pc.addBundledComponent(new OpticalDiscDrive());
        pc.setName("Intel Core-i9 11th Gen PC");
    }

    public Computer getComputer() {
        return pc;
    }  
}
