#include <ansi.h>
#include <weapon.h>
inherit HAMMER;
void create()
{
set_name("[1;36m­·¯«Âñ[0m",({"wind hammer","hammer"}));
set_weight(40000);
     if( clonep() )
               set_default_object(__FILE__);
     else {
            set("long","\n
³o§â©òÀY´¿¸g³Q­·¯«¬Iªk¦b¤W­±,ÁöµM«Ü­«,¦ý¨Ï¥Î°_¨Ó«o¬Û·í«K§Q\n");  
            set("unit", "§â");
            set("rigidity",85); //µw«×
            set("material","steel"); //§÷½è
set("hammer",50);
set("weapon_prop/dex",3);
set("value",4750);
           }
init_hammer(800);
        setup();
}



