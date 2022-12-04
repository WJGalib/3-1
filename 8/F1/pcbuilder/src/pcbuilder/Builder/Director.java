package pcbuilder.Builder;

public class Director {
    IBuilder builder;

    public void construct (IBuilder builder) {
        this.builder = builder;
        this.builder.addBaseComponents();
        this.builder.addBundledComponents();
    }

    public void addMem2666 (IBuilder builder) {
        this.builder.addMemory(2666);
    }

    public void addMem3200 (IBuilder builder) {
        this.builder.addMemory(3200);
    }

    public void addGraphics2G (IBuilder builder) {
        this.builder.addGraphicsCard(2);
    }

    public void addGraphics4G (IBuilder builder) {
        this.builder.addGraphicsCard(4);
    }
}
