/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

/**
 *
 * @author Asus
 */
import java.util.*;
import java.math.BigInteger;
public class G 
{
    public static void main(String[]argc)
    {
    Scanner input= new Scanner(System.in);
    int n= Integer.parseInt(input.next());
    List<BigInteger>list= new ArrayList<>();
    for (int i=1; i<=n; i++)
      list.add(new BigInteger(input.next()));
    while (true)
    {
        //System.out.println(list.size());
        List<BigInteger>list2= new ArrayList<>();
        if (list.size()==1)
            break;
        int check=0;
        for (int i=0;i<list.size();i++)
            if (i!=list.size()-1&&list.get(i).equals(list.get(i+1)))
            {
                list2.add(list.get(i).add(list.get(i+1)));
                i++;
                check=1;
            }
        else
                list2.add(list.get(i));
        if (check==1)  
        {
            list=list2;
            continue;
        }
        List<BigInteger>list3= new ArrayList<>();
        BigInteger mi = list.get(0);
        for (int i=0;i<list.size();i++)
            mi=mi.min(list.get(i));
        for (int i=0;i<list.size();i++)
            if (!list.get(i).equals(mi))
                list3.add(list.get(i));
        list=list3;
    }
    System.out.print(list.get(0));
    }
}