package server.Subject;

import server.Observer.Observer;

public interface Subject {
    public void registerObserver (Observer o);
    public void removeObserver (String oName);
    public void notifyObservers();
}
