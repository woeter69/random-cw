import importClass.importClass;
import myInstitute.Staff;

public class Use {
  public static void main(String[] args) {
    importClass ob = new importClass();
    ob.hello();

    Staff employee1 = new Staff(0001,"Kyla",10000);
    employee1.showStaffDetails();
  }
}
