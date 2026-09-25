class Overload {
  int healthpoint;
  int mana;
  int stamina;
  
  Overload() {
    healthpoint = 100;
    mana = 100;
    stamina = 200;
  }

  Overload(int hp, int fp, int stm) {
    healthpoint = hp;
    mana = fp;
    stamina = stm;
  }
}

class ConsturctorOverload {

  public static void main(String[] args)  {
    Overload player1 = new Overload();
    Overload player2 = new Overload(200, 200, 5);
  }
}

