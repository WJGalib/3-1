package Wing;

public class SafranWing implements Wing{
    String name;
    public SafranWing(){
        this.name = "Safram type Wing";
    }

    @Override
    public String WingName() {
        return name;
    }
}
