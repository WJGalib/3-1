package server.Observer;

import server.ServerState;

public interface Observer {
    public void update (ServerState subPrevState, ServerState subCurrState);
    public String getName();
}
