/*
 * @Author: Dongze Yang
 * @LastEditors: Dongze Yang
 */
package DongzeYang.task3;

import task3.I_Cable;
import task3.I_City;

public class Cable implements I_Cable {

    private I_City c1;
    private I_City c2;

    public Cable(I_City cityOne, I_City cityTwo){
        c1 = cityOne;
        c2 = cityTwo;
    }


    public I_City getCityOne() {
        return c1;
    }


    public I_City getCityTwo() {
        return c2;
    }
}
