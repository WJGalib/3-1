package amogus;

public class Crewmate implements iCrewmate {
    String name;
    public String getName() {
        return this.name;
    }
    public Crewmate (String name) {
        this.name = name;
        System.out.println(getName() + " has joined the voyage.");
    }

    public void fixWiring() {
        System.out.println(name + " is fixing wires.");
    }

    public void cleanVent() {
        System.out.println(name + " is cleaning a vent.");
    }

    public void startReactor() {
        System.out.println(name + " is starting the reactor.");
    }

    public void cleanOxygenFilters() {
        System.out.println(name + " is cleaning an O2 filter.");
    }

    public void alignEngines() {
        System.out.println(name + " is aligning the engines.");
    }

    public void makeBurger() {
        System.out.println(name + " is making a burger in the kitchen.");
    }

    public void emptyGarbage() {
        System.out.println(name + " is emptying the garbage.");
    }
};
