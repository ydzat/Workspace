/*
 * @Author: Dongze Yang
 * @LastEditors: Dongze Yang
 */
package DongzeYang.task3;

import task3.I_Cable;
import task3.I_CableNetwork;
import task3.I_City;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Collections;

public class CableNetwork implements I_CableNetwork {

    private List<I_City> cities = new LinkedList<I_City>();
    private List<List<I_City>> connectList = new LinkedList<List<I_City>>();
    private int edge[][];
    private List<I_Cable> cb = new LinkedList<I_Cable>();
    
    public CableNetwork(){

    }

   
    public I_City addCity(String cityName) {
        if (cities.size() == 0) {
            
            I_City temp = new City(cityName);
            cities.add(temp);
            ArrayList<I_City> temp2 = new ArrayList<I_City>();
            temp2.add(temp);
            connectList.add(temp2);
        }
        else {
            if (checkName(cityName) != -1) {
                return cities.get(cities.size()-1);
            }
            I_City temp = new City(cityName);
            cities.add(temp);
            ArrayList<I_City> temp2 = new ArrayList<I_City>();
            temp2.add(temp);
            connectList.add(temp2);
        }
        

        return cities.get(cities.size()-1);
    }

    
    public void connectCities(I_City cityOne, I_City cityTwo) {
        
        connectList.get(checkName(cityOne.getName())).add(cityTwo);
        connectList.get(checkName(cityTwo.getName())).add(cityOne);
        Cable t = new Cable(cityOne, cityTwo);
        cb.add(t);
    }

    
    public List<I_Cable> maximumDataFlowBetween(List<I_City> citySetOne, List<I_City> citySetTwo) {
        Cable set;
        List<I_Cable> res = new LinkedList<I_Cable>();
        for (int i = 0; i < citySetOne.size(); i++) {
            for (int j = 0; j < citySetTwo.size(); j++) {
                if (edge[checkName(citySetOne.get(i).getName())][checkName(citySetTwo.get(j).getName())] == 1) {
                    int flag = 0;
                    for (int k = i + 1; k < citySetOne.size(); k++) {
                        if (edge[checkName(citySetOne.get(k).getName())][checkName(citySetTwo.get(j).getName())] == 1) {
                            flag = 1;
                            break;
                        }
                    }
                    if (flag == 0) {
                        set = new Cable(citySetOne.get(i), citySetTwo.get(j));
                        res.add(set);
                        break;
                    }
                    
                }
                
            }
        }

        return res;
    }

    public List<List<I_City>> divideCitiesOptimal() {
        setEdge();
        
        List<Integer> set1 = new LinkedList<Integer>();
        List<Integer> set2 = new LinkedList<Integer>();
        for (int i = 0; i < cities.size(); i++) {
            set1.add(i);
        }
        int n = cities.size();
        int noteTo2 = 0;
        for (int i = 1; i < n; i++) {
            if (edge[0][i]==1) {
                set2.add(i);
                
                for (int j = 0; j < set1.size(); j++) {
                    if (set1.get(j) == i) {
                        set1.remove(j);
                        noteTo2 = j;
                        break;
                    }
                } 
            } 
        }

        if (noteTo2 == 0) {
            return null;
        }

        boolean flag = (setCheck(set1) && setCheck(set2)) ? true : false;
        List<List<I_City>> res = new LinkedList<List<I_City>>();
        if (flag == true) {
            List<I_City> t1 = new LinkedList<I_City>();
            List<I_City> t2 = new LinkedList<I_City>();
            for (int i = 0; i < set1.size(); i++) {
                t1.add(cities.get(set1.get(i)));  
            }
            
            for (int i = 0; i < set2.size(); i++) {
                t2.add(cities.get(set2.get(i)));
            }

            res.add(t1);
            res.add(t2);
            
        }
        else {
            res = null;
        }
        

        return res;
    }

    //-----------------------
    private int checkName(String cityName) {
        
        for (int i = 0; i < cities.size(); i++) {
            if (cities.get(i).getName() == cityName) {
                
                return i;
            }
            
        }
        return -1;
    }

    private void setEdge() {
        int n = cities.size();
        
        edge = new int[n][n];
        for (int i = 0; i < n; i++) {

            for (int j = 0; j < connectList.get(i).size(); j++) {
                edge[i][checkName(connectList.get(i).get(j).getName())] = 1;
                
            }
        }
        
        
    }

    // public void getConn() {
    //     for (int i = 0; i < connectList.size(); i++) {
    //         for (int j = 0; j < connectList.get(i).size(); j++) {
    //             System.out.print(connectList.get(i).get(j).getName() + " ");
    //         }
    //         System.out.print("\n");
    //     }
    // }

        
    // public void showCity() {
    //     for (int i = 0; i < cities.size(); i++) {
    //         System.out.println("city = " + cities.get(i).getName());
    //     }
    // }

    private boolean setCheck(List<Integer> set) {
        for (int i = 0; i < set.size(); i++) {
            for (int j = i + 1; j < set.size(); j++) {
                if (set.get(i) == set.get(j)) {
                    return false;
                }
            }
        }

        
        return true;
    }


    
}
