package Engine;

public class SafranEngine implements Engine{
    String name;
    public SafranEngine(){
        this.name = "Safram type Engine";
    }
    @Override
    public String EngineName() {
        return name;
    }
}
