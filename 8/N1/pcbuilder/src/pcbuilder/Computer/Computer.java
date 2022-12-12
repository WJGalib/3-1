package pcbuilder.Computer;

import java.util.*;
import pcbuilder.Component.*;

public class Computer {
    private String name;
    private LinkedList<Component> baseComponents;
    private LinkedList<Component> bundledComponents;
    private LinkedList<Component> customComponents;
    private int basePrice = 0;

    public Computer () {
        baseComponents = new LinkedList<Component>();
        bundledComponents = new LinkedList<Component>();
        customComponents = new LinkedList<Component>();
        this.basePrice = 0;
    }

    public void setName (String name) {
        this.name = name;
    }

    public void setBasePrice (int p) {
        this.basePrice = p;
    }

    private int getBundledComponentPrice() {
        int price = 0;
        for (Component c : bundledComponents) {
            price += c.price();
        }
        return price;
    }
    
    private int getCustomComponentPrice() {
        int price = 0;
        for (Component c : customComponents) {
            price += c.price();
        }
        return price;
    }

    private int getAddedComponentPrice() {
        return getBundledComponentPrice() + getCustomComponentPrice();
    }

    private int getTotalPrice() {
        return getAddedComponentPrice() + basePrice;
    }

    public void addBaseComponent (Component c) {
        baseComponents.addLast(c);
    }

    public void addBundledComponent (Component c) {
        bundledComponents.addLast(c);
    }

    public void addCustomComponent (Component c) {
        customComponents.addLast(c);
    }

    public void printDetails() {
        System.out.println("\n——————————————————————————————————————————————————");
        System.out.println(name);
        System.out.println("——————————————————————————————————————————————————");
        if (baseComponents.isEmpty() == false) {
            System.out.println("Base Components: (Price " + basePrice + " BDT)");
            System.out.println("------------------------------------------------");
            for (Component b : baseComponents) {
                System.out.println(b.name() );
            }
            System.out.println("——————————————————————————————————————————————————");
        }
        System.out.println("Added Components: ");
        System.out.println("-----------------");
        for (Component c : bundledComponents) {
            System.out.println(c.name() + " — " + c.price() + " BDT");
        }
        System.out.println("——————————————————————————————————————————————————");
        System.out.println("Price was increased by " + getCustomComponentPrice() +
                             " BDT for adding the following custom components: ");
        if (customComponents.isEmpty() == false) {
            for (Component c : customComponents) {
                System.out.println(c.name() + " — " + c.price() + " BDT");
            }
            System.out.println("——————————————————————————————————————————————————");
            System.out.println("Total Price: " + getTotalPrice() + " BDT");
            System.out.println("——————————————————————————————————————————————————\n");
        }

    }

}
