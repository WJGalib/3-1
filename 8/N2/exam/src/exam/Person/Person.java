package exam.Person;

import exam.Mediator;

public abstract class Person {
    protected Mediator mediator;
    protected String name;

    public Person (Mediator mediator) {
        this.mediator = mediator;
    }

    public String getName() {
        return this.name;
    }
}
