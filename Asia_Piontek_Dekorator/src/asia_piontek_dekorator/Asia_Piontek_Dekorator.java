
package asia_piontek_dekorator;

import java.util.ArrayList;
import java.util.List;



abstract class AbstarkcyjnaGitara 
{
    protected String opis;
 
    public String geter_opis() 
    {
        return opis;
    }
    
    public abstract double cena();
 
    public String wypisz() 
    {
        return cena() + "(" + geter_opis() + ")";
    }
}


class gitara extends AbstarkcyjnaGitara 
{
    protected double cenna=700;
    public gitara() 
    {
        opis = "gitara bez strun i kluczy ";
    }
 
    public double cena() 
    {
        return cenna;
    }
    
}


abstract class AbstrakcyjnaGitara_dekorator extends AbstarkcyjnaGitara 
{
    protected AbstarkcyjnaGitara kompletowanie_gitary;
 
    public AbstrakcyjnaGitara_dekorator(AbstarkcyjnaGitara kompletowanie_gitary) 
    {
        this.kompletowanie_gitary = kompletowanie_gitary;
    }

    public abstract String geter_opis();
}



class struny_dekorator extends AbstrakcyjnaGitara_dekorator 
{
    protected double cenna=20;
    public struny_dekorator(AbstarkcyjnaGitara kompletowanie_gitary) 
    {
        super(kompletowanie_gitary);
    }
 
    public String geter_opis() 
    {
        return kompletowanie_gitary.geter_opis() + " + struny";
    }
 
    public double cena() 
    {
        return kompletowanie_gitary.cena() + cenna;
    }
    
}
 
class klucze_dekorator extends AbstrakcyjnaGitara_dekorator 
{
 protected double cenna=60;
    public klucze_dekorator(AbstarkcyjnaGitara kompletowanie_gitary) 
    {
        super(kompletowanie_gitary);
    }
 
    public String geter_opis() 
    {
        return kompletowanie_gitary.geter_opis() + " + klucze";
    }

    public double cena() 
    {
        return kompletowanie_gitary.cena() + cenna;
    }
    
}
 
class stroik_dekorator extends AbstrakcyjnaGitara_dekorator 
{
    protected double cenna=30;
    public stroik_dekorator(AbstarkcyjnaGitara kompletowanie_gitary) 
    {
        super(kompletowanie_gitary);
    }

    public String geter_opis() 
    {
        return kompletowanie_gitary.geter_opis() + " + stroik do gitary";
    }
     public double cena() 
    {
        return kompletowanie_gitary.cena() + cenna;
    }
    
}
class kostki_dekorator extends AbstrakcyjnaGitara_dekorator 
{
    protected double cenna=15;
    public kostki_dekorator(AbstarkcyjnaGitara kompletowanie_gitary) 
    {
        super(kompletowanie_gitary);
    }

    public String geter_opis() 
    {
        return kompletowanie_gitary.geter_opis() + " + komplet kostek do gitary";
    }
     public double cena() 
    {
        return kompletowanie_gitary.cena() + cenna;
    }
    
}


public class Asia_Piontek_Dekorator
{


    public static void main(String[] args) 
    {

         AbstarkcyjnaGitara gitara;

         gitara = new gitara();

         System.out.println(gitara.wypisz());

         gitara = new gitara();
         gitara = new struny_dekorator(gitara);
         gitara = new stroik_dekorator(gitara);
         gitara = new klucze_dekorator(gitara);
         System.out.println(gitara.wypisz());
        
         gitara = new gitara();
         gitara = new struny_dekorator(gitara);

         System.out.println(gitara.wypisz());
         
         gitara = new gitara();
         gitara = new kostki_dekorator(gitara);

         System.out.println(gitara.wypisz());
    }
    
}
