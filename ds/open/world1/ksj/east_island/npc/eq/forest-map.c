#include <path.h>
inherit ITEM;

void create()
{
  set_name("碍ぇ此瓜", ({"forest map","map"}) );
  set("long",@long
磞酶帝碍ぇ此眎瓜

            
            隔      ━
              
        此⌒此⌒━⌒━⌒━
                
        此⌒此⌒此⌒此⌒此
                
        此⌒此⌒此⌒此⌒此
                
            此⌒此⌒此
                
                隔⌒隔
                    
                      

long);      
  set_weight(250);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "眎");
    set("volume",1);
    set("no_sell",1);
  }
  setup(); 
}
