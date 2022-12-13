package Wing;

public class BoeingWing implements Wing{
    String name;
    public BoeingWing(){
        this.name = "Boeing type Wing";
    }

    @Override
    public String WingName() {
        return name;
    }
}
