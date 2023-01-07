package server.Observer;

import server.Subject.CompanyServer;

public class User {
    
    UserState state;
    CompanyServer server;
    String name;

    public User (String name) {
        this.name = name;
        this.state = UserState.ONSITE;
    }

    public void setState (UserState state) {
        this.state = state;
        System.out.println("State of " + this.getName() + " updated to: " + this.state.getName());
    }

    public UserState getState() {
        return this.state;
    }

    public String getName() {
        return this.name;
    }
}
