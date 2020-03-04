#include <ansi.h>
#include <weapon.h>

inherit BLADE;

void create()
{
              set_name(HIW"¥ú¼v¤M"NOR,({"light blade","blade"}));
              set("long","¤@§â¦èÄ¹ªº¥ú¼v¤M¡A·|µo¥X»È¥Õ¦â¥ú¼v.\n");
              set_weight(3000);
              if( clonep() )
                      set_default_object(__FILE__);
              else {
                    set("unit", "§â");
                    set("value",1000);
                    set("material","iron");
                 }
                 init_blade(10);
set("combat_msg", ({    //§ðÀ»°T®§ $N¬O¦Û¤v $n¬O¹ï¤è $l ¬O¹ï¤è¨ü§ð³¡¦ì $w¬OªZ¾¹Ù
                "$N¤â´¤$w¡A¥u¨£»È¥Õ¦â¼v¥ú¤@°{¡A«K´Â$nªºÀY³¡¤@¬å\n",
                "$N§â$w©¹$nªº¨{¤l¬½¬½¦a¤@Ñ¶¡A¹y®É$n¦å¬y¤jª`¡A¼Q¨ì$NÁy¤W\n",
                "$N¥Î$w©¹$nªº¸}¸ò³¡¨ë¥h¡Aµ²ªG$nµhªº«z«z¤j¥s\n",
                "$N±N$w¤@¤Ï®³¡A«K¦V$nªº¤â³¡¾î¬å\n",
                "$N¤j¥s¡G¡u³Ü!±þ!¡v¡A§â$n¥Ñ¤W©¹¤U¤@¤j¬å\n",
                "$N§â$w©¹$nªº¨{¤l¬½¬½¦a¤@Ñ¶¡A¹y®É$n¦å¬y¤jª`¡A¼Q¨ì$NÁy¤W\n",
                "$N¥Î$w©¹$nªº¸}¸ò³¡¨ë¥h¡Aµ²ªG$nµhªº«z«z¤j¥s\n",
                "$N±N$w¤@¤Ï®³¡A«K¦V$nªº¤â³¡¾î¬å\n",
                "$N¤j¥s¡G¡u³Ü!±þ!¡v¡A§â$n¥Ñ¤W©¹¤U¤@¤j¬å\n",
    }) );
           setup();
}

