
package wp_singelton;





    class Element                              //Deklaracja Klasy Elementy
    {
	public int wartosc;                    
	public Element next;                    // nastempny element listy
	
	Element(int wartosc)                    //kostruktor Klasy Elementy
        {
		this.wartosc = wartosc;
		next = null;
	}
    }
    
    
    class Lista                                 // klasa obsługująca liste
    {                            
	private static Lista obiekt = null;     
	private int ilosc_elementow;
	private Element pierwszy;
	private Element ostatni;
	
	static Lista getInstance()              //  twożenie nowej Listy
        {
		if(obiekt == null)
			obiekt = new Lista();
		
		return obiekt;
	}
	
	private Lista()                             //Kostruktor klasy Lista
        {
		ilosc_elementow = 0;
		pierwszy = null;
		ostatni = null;
	}
	
	
        
        Lista Wyswietl()                            //wyświetlenie całej listy
        {
		Element element = pierwszy;
		while(element != null) 
                {
			System.out.println(element.wartosc);
			element = element.next;
		}
		
		return this;
	}
	
        Lista Dodaj(int wartosc)                   //dodanie nowego elementu listy
        {
		if(ilosc_elementow == 0) 
                {
			pierwszy = new Element(wartosc);
			ostatni = pierwszy;
		}
		else 
                {
			Element element = new Element(wartosc);
			ostatni.next = element;
			ostatni = element;
		}
		
		ilosc_elementow++;
                
		return this;
	}
	int Podaj_ilosc()                       // zwraca ilość elementów w liście
        {
		return ilosc_elementow;
	}
        
        Lista UsunOstani()                      // usuwa ostatni element w liście
        {
		if(ilosc_elementow == 0) 
                {
			System.out.println("Brak elementów listy.");
                        
                        
			return this;
		}
		else if(ilosc_elementow == 1) 
                {
			pierwszy = null;
			ostatni = null;
			ilosc_elementow = 0;
                        
                        
			return this;
		}
		else 
                {
			Element element = pierwszy;
                        
			while(element.next != ostatni) 
                        {
				element = element.next;
			}
			
			ostatni = element;
			element.next = null;
                        
			return this;
		}
	}

	
	
}
public class WP_Singelton 
{
    public static void main(String[] args) 
    {
      Lista a = Lista.getInstance();  
      
      System.out.println(a.Dodaj(1).Dodaj(2).Dodaj(3).Wyswietl());
      System.out.println(a.UsunOstani().Wyswietl());
    }
    
}