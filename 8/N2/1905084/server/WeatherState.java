package server;

public enum WeatherState {

    SUNNY {
        @Override
        public String getName() {
            return "Sunny";
        } 
    },
    RAINY {
        @Override
        public String getName() {
            return "Rainy";
        } 
    },
    SNOWY {
        @Override
        public String getName() {
            return "Snowy";
        } 
    },
    HEAVY_SNOW {
        @Override
        public String getName() {
            return "Very Snowy";
        } 
    },
    STORM {
        @Override
        public String getName() {
            return "Stormy";
        } 
    };;

    public abstract String getName();

}
