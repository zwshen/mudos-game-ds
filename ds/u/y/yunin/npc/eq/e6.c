#include <armor.h>



#include <ansi.h>



inherit WAIST;



void create()



{



        set_name(HIC"Ａ級神束腰"NOR ,({ "level A waist","waist" }) );



        set_weight(1300);



        if( clonep() )



                set_default_object(__FILE__);



        else {



 set("long",@LONG

天界恐怖人們所戴的束腰﹗

LONG



     );









        set("unit", "個");



        set("value",2300);



        set("material", "gold");



        set("armor_prop/shield",1);







        set("armor_prop/armor",5);



        }



        setup();



}
