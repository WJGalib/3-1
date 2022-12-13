package Engine;

public class AirbusEngine implements Engine{
    String name;
    public AirbusEngine(){
        this.name = "Airbus type Engine";
    }
    @Override
    public String EngineName() {
        return name;
    }
}
