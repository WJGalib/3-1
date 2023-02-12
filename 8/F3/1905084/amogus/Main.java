package amogus;

import java.util.ArrayList;
import java.util.Random;
import java.util.Scanner;

public class Main {


    public static void main(String[] args) throws Exception {

        Random rand = new Random();
        System.out.println("\n——————————————————");
        System.out.println("     AMONG US     ");
        System.out.println("——————————————————\n");
        System.out.println ("\u001B[31m" + "(Only imposters communicate in red among themselves.)\n" + "\u001B[0m");

        iCrewmate cm1 = new Crewmate("Tom");
        iCrewmate cm2 = new Crewmate("Jack");
        Imposter im1 = new Imposter("John");
        iCrewmate cm3 = new CrewmateAdapter(im1);
        ArrayList<iCrewmate> crew = new ArrayList<iCrewmate>();
        crew.add(cm1);
        crew.add(cm2); 
        crew.add(cm3);

        System.out.println();
        for (int k=0; k<5; k++) {
            for (int i = rand.nextInt(3), j=0; j<3; i=(i+1)%3, j++) {
                int task = rand.nextInt(7);
                if (task==0) crew.get(i).fixWiring();
                else if (task==1) crew.get(i).cleanVent();
                else if (task==2) crew.get(i).startReactor();
                else if (task==3) crew.get(i).cleanOxygenFilters();
                else if (task==4) crew.get(i).alignEngines();
                else if (task==5) crew.get(i).makeBurger();
                else crew.get(i).emptyGarbage();
            }
            System.out.println();
        }
        System.exit(0);
    }
}
