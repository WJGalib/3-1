package server.Subject;

import java.util.ArrayList;

import server.ServerState;
import server.Observer.Observer;

public class CompanyServer implements Subject {

    ArrayList<Observer> observers;
    ServerState currState, prevState;    

    public CompanyServer() {
        observers = new ArrayList<Observer>();
        currState = ServerState.OPERATIONAL;
    }

    public void setCurrState (ServerState state) {
        if (state == this.currState) {
            System.out.println("Already in " + state.getName() + " state!");
            return;
        }
        this.prevState = this.currState;
        this.currState = state;
        notifyObservers();
    }

    public ServerState getCurrState() {
        return this.currState;
    }

    public ServerState getPrevState() {
        return this.prevState;
    }

    public void registerObserver (Observer o) {
        observers.add(o);
    }

    public void removeObserver (String oName) {
        for (Observer o : observers) {
            if (o.getName().equalsIgnoreCase(oName)) {
                observers.remove(o);
                return;
            }
        }
    } 

    public void notifyObservers() {
        for (Observer o : observers) o.update(this.prevState, this.currState);
    }
}
