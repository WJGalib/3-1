package server.Observer;

import server.WeatherState;

public interface Observer {
    public void getAlert (String alert);
    public void update (int temp, WeatherState subCurrState);
    public String getName();
}
