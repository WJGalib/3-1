import Factory.AirbusFactory;
import Factory.BoeingFactory;
import Factory.PlaneFactory;
import Factory.SafranFactory;

public class FactoryProducer {
    public static PlaneFactory getPlane(String st){
        if(st.equalsIgnoreCase("Boeing"))
            return new BoeingFactory();
        else if(st.equalsIgnoreCase("Airbus"))
            return new AirbusFactory();
        else if(st.equalsIgnoreCase("Safran"))
            return new SafranFactory();
        else
            System.out.println("Invalid Company Name.");

        return null;
    }
}
