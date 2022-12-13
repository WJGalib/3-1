package Engine;

public class BoeingEngine implements Engine{
    String name;
    public BoeingEngine(){
        this.name = "Boeing type Engine";
    }

    @Override
    public String EngineName() {
        return name;
    }
}
