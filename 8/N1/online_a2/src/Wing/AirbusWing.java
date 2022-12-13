package Wing;

public class AirbusWing implements Wing{
    String name;
    public AirbusWing(){
        this.name = "Airbus type Wing";
    }

    @Override
    public String WingName() {
        return name;
    }
}
