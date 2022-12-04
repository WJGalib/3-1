package pcbuilder.Builder;

import pcbuilder.Computer.Computer;
import pcbuilder.Component.GraphicsCard.*;
import pcbuilder.Component.Memory.*;

public abstract class IBuilder {
    
    protected Computer pc = new Computer();

    public abstract void addBaseComponents();
    public abstract void addBundledComponents();
    // public void addCustomComponents();

    public void addMemory (int freq) {
        if (freq == 2666) pc.addCustomComponent(new Mem2666());
        else if (freq == 3200) pc.addCustomComponent(new Mem3200());
    }

    public void addGraphicsCard (int capacity) {
        if (capacity == 2) pc.addCustomComponent(new Graphics2G());
        else if (capacity == 4) pc.addCustomComponent(new Graphics4G());
    }

    public abstract Computer getComputer();
}
