package amogus;

public class CrewmateAdapter implements iCrewmate {
    Imposter imposter;

    public CrewmateAdapter (Imposter imposter) {
        this.imposter = imposter;
        Imposter.printRed(getName() + " has started using the Crewmate Adapter as a disguise.");
    }
    public String getName() {
        return this.imposter.getName();
    }

    public void fixWiring() {
        System.out.println(getName() + " is fixing wires.");
        imposter.cutPower();
    }

    public void cleanVent() {
        System.out.println(getName()  + " is cleaning a vent.");
        imposter.passVent();
    }

    public void startReactor() {
        System.out.println(getName()  + " is starting the reactor.");
        imposter.meltdownReactor();
    }

    public void cleanOxygenFilters() {
        System.out.println(getName()  + " is cleaning an O2 filter.");
        imposter.depleteOxygen();
    }

    public void alignEngines() {
        System.out.println(getName()  + " is aligning the engines.");
        imposter.overpowerEngine();
    }

    public void makeBurger() {
        System.out.println(getName()  + " is making a burger in the kitchen.");
        imposter.poisonFood();
    }

    public void emptyGarbage() {
        System.out.println(getName()  + " is emptying the garbage.");
        imposter.ejectCrewmate();
    }
}
