#include <ansi.h>
#include <weapon.h>
inherit SPEAR;
void create()
{
set_name("[1;34m³Á[1;32m§J[1;35mµ§[0m",({"mike pen","mike","pen"}));
// ³]"mike pen","pen","mike"³o¼Ëwield®Éwield pen or wield mike or wield mike pen´N¥i¸Ë³Æ
set_weight(5000);
if( clonep() )
    set_default_object(__FILE__);
  else {
set("long","\n
§A¬Ý¨ì¤@¤ä¤pµe®a§@µe®É¥Î¨ìªº±m¦â³Á§Jµ§³á!\n");
set("unit", "§â");
set("unequip_msg", "$N±N¤â¤¤ªº$n©ñ¤J®Ñ¥]¤º¡C\n");
set("wield_msg","$N®³°_¤F$n,[1;36m¤@ªÑµe®a°l¨D[1;5;31m§¹¬ü[0m[1;36mªº·N©À´é¤W§A¤ßÀY[0m\n");
set("spear",25); //ªÀ¤F³o­Ó..¥Nªískill 50¤~¯àwield¥B¤]³]©w¤FªZ¾¹ªº§ðÀ»¤O..§ðÀ»¤O¤º©w¬OpudonªÀªº...§A¦Û¤vtry
set("value",800);
       }
      setup();
}
