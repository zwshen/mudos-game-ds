#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIW"¹q¸£"NOR,({"computer"}) );
set_weight(20);
   set("long","
¥Ø«e¦b¿Ã¹õ¤W¯B²{ªº¿ï¶µ¦³(push number):
[36m1[0m:                       [35m ªZ¾¹¤§¶¡[0m.[35m [0m
¦r¹õ¥X¾ã»ôªº±Æ¦C¥X:
¡u¦b³o¸Ì§A¥i¥HºÉ±¡ªº¶}ºj¡A¨S¤H·|ªý¤î§A¡A¥u¬O«áªG¦Û­t¡C¡v
                                     Copyright(C) ---¶W¡E¥ú¤l½m²ß³õ(Super-light-area)---
");
        if( clonep() )
                set_default_object(__FILE__);
 else { 
 set("unit", "­Ó");
 set("no_get",1);
 set("value", 1); 
 set("no_sac",1);
 }
setup();
}
