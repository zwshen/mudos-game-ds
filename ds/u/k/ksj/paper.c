#include <ansi.h>
#include <path.h>
inherit ITEM;

void create()
{
        set_name("¤p¯È±ø", ({"small paper","paper"}));
        set("long",@LONG
¯È±ø¤W¼gµÛ¡G

  ¿Kª¢¦åÅï©Ü(blood-scale surcoat) ¨¾+17  Å]¨¾+2
  îîÅ]¤â(dark gloves)             ¨¾+9
  ¯«¥ú´¹­±(crystal mask)          ¨¾+3   Å]¨¾+5
  ºÏ¤ÞÅ@¤â(magnetic wrists)       ¨¾+8
  °j¥ú¹P¥Ò§Ù(refractile ring)     ¨¾+5
  ´HÅKÀVÀô(ice-iron neck)         ¨¾+5
  ¤EÄ_ª÷«a(nine-gem crown)        ¨¾+10  Å]¨¾+6
  Æ[¦tÂù·¥³T(ice-fire cloth)      ¨¾+26
  ¤K¨ö¦Xª÷¬Þ(eight-metal shield)  ¨¾+28
  ¬Pªe¾ÔñZ(galaxy armor)          ¨¾+42
  ·à§q¸y±a(lion waist)            ¨¾+8
  »ñµ¾»È¹u(phoenix boots)         ¨¾+15
  ¦Bµ·ÄñÀs¿Ç(ice-dragon pants)    ¨¾+10
LONG
        );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("no_get",1);
        set("no_drop",1);
        set("unit", "­Ó");
        set("volume",1000);
        set("value",500);
        }
        setup(); 
}
