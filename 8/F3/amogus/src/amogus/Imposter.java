package amogus;

public class Imposter {
    String name;
    public String getName() {
        return this.name;
    }
    public Imposter (String name) {
        this.name = name;
        System.out.println(getName() + " has joined the voyage.");
    }

    public static void printRed (String str) {
        System.out.println ("\u001B[31m" + str + "\u001B[0m");
    }

    public void cutPower() {
        printRed(name + " is actually cutting the power!");
    }

    public void passVent() {
        printRed(name + " is actually passing through a vent!");
    }

    public void meltdownReactor() {
        printRed(name + " is actually melting down the reactor!");
    }

    public void depleteOxygen() {
        printRed(name + " is actually depleting oxygen!");
    }

    public void overpowerEngine() {
        printRed(name + " is actually overpowering an engine!");
    }

    public void poisonFood() {
        printRed(name + " is actually poisoning the food in the kitchen!");
    }

    public void ejectCrewmate() {
        printRed(name + " is actually ejecting a crewmate into space!!");
    }
};
