
package fabric;




import java.util.ArrayList;
import java.util.Collections;

interface MojInterface {
    void deleteItem(int index);
    void addItem(String name);
    ArrayList<String> listItems();
    ArrayList<String> sortItems();
}

class Users implements MojInterface {
    private ArrayList<String> items;

    public Users() {
        items = new ArrayList<String>();
        addItem("User Kalina");
        addItem("User Bożena");
        addItem("User Albert");
        addItem("User Zykfryd");
    }
    

    public void deleteItem(int index) {
        items.remove(index);
    }

    public void addItem(String name) {
        items.add(name);
    }

    public ArrayList<String> listItems() {
        return items;
    }

    public ArrayList<String> sortItems() {
        Collections.sort(items);
        return items;
    }
}

class Products implements MojInterface {
    private ArrayList<String> items;

    public Products() {
        items = new ArrayList<String>();
        addItem("Products pierwszy");
        addItem("Products drugi");
        addItem("Products trzeci");
        addItem("Products czwarty");
    }
    

    public void deleteItem(int index) {
        items.remove(index);
    }

    public void addItem(String name) {
        items.add(name);
    }

    public ArrayList<String> listItems() {
        return items;
    }

    public ArrayList<String> sortItems() {
        Collections.sort(items);
        return items;
    }
}

class Priviledges implements MojInterface {
    private ArrayList<String> items;

    public Priviledges() {
        items = new ArrayList<String>();
        addItem("Priviledges : tak");
        addItem("Priviledges : nie");
    }
    

    public void deleteItem(int index) {
        items.remove(index);
    }

    public void addItem(String name) {
        items.add(name);
    }

    public ArrayList<String> listItems() {
        return items;
    }

    public ArrayList<String> sortItems() {
        Collections.sort(items);
        return items;
    }
}



class Factory {
    public static MojInterface create(String name) {
        switch(name) {
            case "users":
				return new Users();
				
				
            case "products":
				return new Products();
              
            
            case "priviledges":
				return new Priviledges();                 
				
            default:
				return null;
        }
    }
}



public class Fabric {
    
    


    public static void main(String[] args)
    {
        	MojInterface mojInterface = Factory.create("users");

		for(String item : mojInterface.listItems())
			System.out.println(item);
                
                
                mojInterface.addItem("User Asia");
                
                mojInterface.sortItems();
                
                for(String item : mojInterface.listItems())
			System.out.println(item);
                
                
    }
    
}



