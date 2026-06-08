class Person{
  protected int age;
  String name;

  static int add(int x, int y) {
    return x + y;
  }

  protected void intro() {
    System.out.println("i am a person");
  }
}

class Student extends Person{
  protected void intro() {
    System.out.println("age: " + age + "\nname : " + name);
  }
}

public class Main{
  public static void main(String[] args) {
    Person p1 = new Person();

    int z = Person.add(2, 2);
    System.out.println(z);
  }
}