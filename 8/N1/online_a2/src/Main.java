import Engine.Engine;
import Factory.PlaneFactory;
import Wing.Wing;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter your preferred company name:");
        String company = sc.nextLine();

        PlaneFactory plane = FactoryProducer.getPlane(company);
        if(plane != null){
            System.out.println("Company: "+plane.getCompany());
            System.out.println("Engine: "+plane.getEngine().EngineName());
            System.out.println("Wing: "+plane.getWing().WingName());
        }
    }
}
