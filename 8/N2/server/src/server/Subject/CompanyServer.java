package server.Subject;

import java.util.ArrayList;

import server.WeatherState;
import server.Observer.Observer;

public class CompanyServer implements Subject {

    ArrayList<Observer> observers;
    WeatherState currState, prevState;    
    int prevTemp, currTemp;

    public CompanyServer() {
        observers = new ArrayList<Observer>();
        currState = WeatherState.SUNNY;
        currTemp = 25;
    }

    public void setCurrState (WeatherState state) {
        if (state == this.currState) {
            System.out.println("Already in " + state.getName() + " state!");
            return;
        }
        this.prevState = this.currState;
        this.currState = state;
        if (this.currState == WeatherState.HEAVY_SNOW) alertUsers("POSSIBILITY OF HEAVY SNOW");
        if (this.currState == WeatherState.STORM) alertUsers("POSSIBILITY OF STORM");

        notifyObservers();
    }

    public void setCurrState (WeatherState state, int temp) {
        if (currTemp == temp) System.out.println("Temperature is already this value");
        else {
            prevTemp = currTemp;
            currTemp = temp;
        }
        if (state != this.currState) setCurrState(state);
        else notifyObservers();
    }

    public WeatherState getCurrState() {
        return this.currState;
    }

    public WeatherState getPrevState() {
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
        for (Observer o : observers) o.update(this.currTemp, this.currState);
    }

    public void alertUsers (String alert) {
        for (Observer o : observers) o.getAlert(alert);
    }
}
