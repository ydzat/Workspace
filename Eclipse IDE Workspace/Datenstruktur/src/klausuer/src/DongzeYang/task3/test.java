/*
 * @Author: Dongze Yang
 * @LastEditors: Dongze Yang
 */
package DongzeYang.task3;

import java.util.List;

public class test {
    public static void main(String[] args) {
    
        I_CableNetwork network = new CableNetwork();
        I_City[] cities = new I_City[4];
        
        cities[0] = network.addCity("Chemnitz"); 
        cities[1] = network.addCity("Leipzig"); 
        cities[2] = network.addCity("Dresden"); 
        cities[3] = network.addCity("Mittweida");
        
        network.connectCities(cities[0], cities[1]);
        
        network.connectCities(cities[0], cities[2]);
        
        network.connectCities(cities[2], cities[3]);

        

        List<List<I_City>> t = network.divideCitiesOptimal();
        for (int i = 0; i < t.size(); i++) {
            for (int j = 0; j < t.get(i).size(); j++) {
                System.out.print(t.get(i).get(j).getName() + " ");
            }
            System.out.print("\n");
        }

        List<I_City> t1 = t.get(0);
        List<I_City> t2 = t.get(1);
        List<I_Cable> tt = network.maximumDataFlowBetween(t1, t2);

        for (int i = 0; i < tt.size(); i++) {
            System.out.println(tt.get(i).getCityOne().getName()+" "+tt.get(i).getCityTwo().getName());
            
        }










    }
}