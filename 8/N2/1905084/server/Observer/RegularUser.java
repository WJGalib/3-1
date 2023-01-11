package server.Observer;

import server.WeatherState;
import server.Subject.CompanyServer;

public class RegularUser extends User implements Observer {

    public RegularUser (CompanyServer server, String name) {
        super(name);
        this.server = server;
        this.server.registerObserver(this);
    }
    
    public String showName() {
        return "REGULAR USER " + this.name;
    }

    public void update (int temp, WeatherState subCurrState) {

        System.out.println("\u001B[33m");
        System.out.println(this.showName() + " is notified that weather is now " + subCurrState.getName());
        System.out.println("..and the temperature is " + temp + " degrees Celsius");


        // int input;
        // if (subPrevState == WeatherState.OPERATIONAL && subCurrState == WeatherState.PARTIAL_DOWN) {
        //     System.out.println("Asking " + this.showName() + " for decision: (Enter no.)");
        //     System.out.println("1) Continue using limited functionality on ABC Server");
        //     System.out.println("2) Switch over to DEF Server for $20 per hour (default)");
        //     input = Input.scanInt();
        //     if (input == 1) setState(UserState.PART_ONSITE);
        //     else if (input == 2) setState(UserState.FULL_OFFSITE);
        //     else {
        //         System.out.println("Invalid input, choosing default.");
        //         setState(UserState.FULL_OFFSITE);
        //     }
        // } else if ((subPrevState == WeatherState.OPERATIONAL || subPrevState == WeatherState.PARTIAL_DOWN && this.state == UserState.PART_ONSITE) 
        //           && subCurrState == WeatherState.FULL_DOWN) {
        //     System.out.println("Asking " + this.showName() + ": Would you like to start using DEF Server for $20 per hour?");
        //     System.out.println("1) Yes (default) \n2) No");
        //     input = Input.scanInt();
        //     if (input == 1) setState(UserState.FULL_OFFSITE);
        //     else if (input == 2) setState(UserState.OFFGRID);
        //     else {
        //         System.out.println("Invalid input, choosing default.");
        //         setState(UserState.FULL_OFFSITE);
        //     }
        // } else if (subPrevState != WeatherState.OPERATIONAL && subCurrState == WeatherState.OPERATIONAL) {
        //     boolean bill = false;
        //     if (this.state == UserState.FULL_OFFSITE) bill = true;
        //     setState(UserState.ONSITE);
        //     if (bill) System.out.println("Bill sent to " + this.showName() + " for taking service from DEF Server without Premium.");
        // }
        System.out.println("\u001B[0m");

    }


    public void getAlert (String alert) {
        System.out.println("\u001B[33m");
        System.out.println("SEVERE WEATHER ALERT RECEIVED BY " + this.showName() + "!!!");
        System.out.println(alert);
        System.out.println("\u001B[0m");

    }
}
