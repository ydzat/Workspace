package task3;
import java.util.List;

public interface I_CableNetwork {
    I_City addCity(String cityName);
    void connectCities(I_City cityOne, I_City cityTwo);
    List<I_Cable> maximumDataFlowBetween(List<I_City> citySetOne, List<I_City> citySetTwo);
    List<List<I_City>> divideCitiesOptimal();
}
