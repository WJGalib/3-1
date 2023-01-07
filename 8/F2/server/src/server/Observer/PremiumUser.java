package server.Observer;

import server.Input;
import server.ServerState;
import server.Subject.CompanyServer;

public class PremiumUser extends User implements Observer {

    public PremiumUser (CompanyServer server, String name) {
        super(name);
        this.server = server;
        this.server.registerObserver(this);
    }
    
    public String showName() {
        return "PREMIUM USER " + this.name;
    }

    public void update (ServerState subPrevState, ServerState subCurrState) {

        System.out.println("\u001B[31m");
        System.out.println(this.showName() + " is notified that ABC server is now " + subCurrState.getName());

        int input;
        if (subPrevState == ServerState.OPERATIONAL && subCurrState == ServerState.PARTIAL_DOWN) {
            System.out.println("Asking " + this.showName() + " for decision: (Enter no.)");
            System.out.println("1) Use ABC and DEF servers both partially (default)");
            System.out.println("2) Switch over to DEF fully");
            input = Input.scanInt();
            if (input == 1) setState(UserState.PART_ON_PART_OFF);
            else if (input == 2) setState(UserState.FULL_OFFSITE);
            else {
                System.out.println("Invalid input, choosing default.");
                setState(UserState.PART_ON_PART_OFF);
            }
        } else if (subPrevState == ServerState.OPERATIONAL && subCurrState == ServerState.FULL_DOWN) {
            setState(UserState.FULL_OFFSITE);
        } else if (subPrevState == ServerState.PARTIAL_DOWN && subCurrState == ServerState.FULL_DOWN) {
            if (this.state == UserState.PART_ON_PART_OFF) setState(UserState.FULL_OFFSITE);
        } else if (subPrevState != ServerState.OPERATIONAL && subCurrState == ServerState.OPERATIONAL) {
            setState(UserState.ONSITE);
        }
        System.out.println("\u001B[0m");

    }
}
