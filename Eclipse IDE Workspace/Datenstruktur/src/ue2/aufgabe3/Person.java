package ue2.aufgabe3;

public class Person {
    private String firstName;
    private String lastName;

    Person(String firstName, String lastName){
        this.firstName = firstName;
        this.lastName = lastName;
    }

    public String getName(){
        return lastName + ", " + firstName;
    }
}
