/*
 * @Author: Dongze Yang
 * @LastEditors: Dongze Yang
 */
package DongzeYang.task3;

import task3.I_City;

public class City implements I_City {
    private String name;


    public City(String name){
        this.name = name;
    }

    
    public String getName() {
        return this.name;
    }
}
