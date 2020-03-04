#include <path.h>
#include <weapon.h>
#include <ansi.h>
inherit F_UNIQUE;
inherit SWORD;
void create()
{
set_name( HIG"¤Q"HIW"¤è"HIY"ÆF"HIW"°Ê"NOR ,({"ten sword","sword"}));
        set_weight(5000+random(1000));
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("long",HIB"
¤@§â´²µo¥XÆF¥úªº¼C,¤W­±ªþµÛµÛµL¼ÆÁûªºÄ_¥Û,
¾W§QµL¤ñ,³s¥ÛÀY³£¯à»´ÃP¤Á¶}¡C\n"NOR);
                set("volume",2);
                set("unit", "§â");
                set("value",12500);
        set("limit_skill",60);
        set("material","silver");
                set("limit_lv",25);
                set("limit_str",30);
                set("limit_dex",35);
        }
        init_sword(80); 
        set("wield_msg","$N±q¸y»Ú©Ô¥X¤F¤@§â$n´¤¦b¤â¤¤,ºñ¦âªº¥ú¨~Åý$Nªº²´·ú¥Rº¡
                           µÛ¥ú¨~,´²µo¥X­¢¤H¤£¤ÎªºÆF®ð ¡C\n");
        set("unequip_msg", "$N©ñ¤U¤â¤¤ªº$n, ±N$n´¡¤J¸y»Úªº¼CÀT¤¤,¥ú¯íº¥º¥¤£¨£¡C\n");
        set("combat_msg", ({
   "$N¨Ï¥X²Ä¤@¦¡¡uºñ¡v,¼C¦yµo¥Xºñ¦âªº®ðÅé,ª½¨R$nÂù²´ "  ,
   "$N¨Ï¥X²Ä¤G¦¡¡u¤b¡v,$N§â¤Q¤èÆF°Ê¤WÂà¤U·Æ,¼C¤b±Ù©¹$nªº¸y»Ú",
   "$N¨Ï¥X¦a¤T¦¡¡uÁô¡v,¤Q¤èÆF°Ê­YÁô­Y²{ªº¥X²{¦b$nªº­±«e,$N´£Án¹B®ð,ª@µØ®ÇÃäªº®ðÅé,§â$n©P³òÅÜ¦¦¨¯uªÅª¬ºA,$nªº°Ê§@ºC¤F¥b©ç,§A¶¶¶Õ§â¼C¤W´£,¹º¦V$nªº»L³¡",
   "$N¨Ï¥X²Ä¥|¦¡¡u¼º¡v,¤Q¤èÆF°Ê¥Ñ¤W±Û¼A¦Ü¤U,©¹$nªº¤â³¡¦Ó¥h",
   "$N¨Ï¥X²Ä¤­¦¡¡uÃz¡v,¤Q¤èÆF°Ê¦³¦p¬µÃÄªºÃz¯}Án,©¹$nªº­I³¡¥h,¹³¸U¤çªº¼C",
   "$N¨Ï¥X²Ä¤»¦¡¡u¦B¡v,¤Q¤èÆF°Ê«æÂà¦Ó¤U,³t«×Åå¤H,¤Q¤èÆF°Êº¥º¥µ²¦B,·Æ¦V$n",
   "$N¨Ï¥X²Ä¤C¦¡¡u°w¡v,$N§â¤Q¤èÆF°Ê§Ö³t²¾°Ê,±qªÅ®ð¹º¹L¤@¨ì¼C®ð®g©¹$n,¹³¤d¸UªK»È°w",
   "$N¨Ï¥X²Ä¤K¦¡¡u«Ê¡v,¥u¨£§A¼L¸Ì°á°á¦³µü,©¿µM¤@¥y:¡u«Ê¡v,$nªº¨­Åé©¿µM¤£¯à°Ê¤F,\n
    §A§â¤Q¤èÆF°Ê©¹$n¨ºÃä¤@©ß,¥¿¦n´¡¶i¤Fµ²¬É,$nÀ~ªº§â¦Û¨­ªZ¾¹¨ë¦V¸¡³¡",
   "$N¨Ï¥X²Ä¤E¦¡¡u¤ß¡v,$NÂó¤WÂù²´,¤âÁÍ¤Q¦r,¤Q¤èÆF°Ê°j±Û¤@¶g,ÂY¥X¼Æ¹D¼C®ð,\n
     ¥þ³¡®g©¹$nªº¤è¦V,¥u¨£$nªF¸ú¦è°{", 
}) ); 
      setup();
}
void attack(object me,object victim)
{
        int damage,str,dex,random1;
        if( random(200)>150)
        {
        str = me->query("str")-random(20);
        dex = me->query("dex")-random(18);
        random1 = 1+random(2);
        damage = random1*(str+dex);
        victim->receive_damage("hp", damage, me );
        message_vision(
        "\n"
        +HIY"$N¨Ï¥X²Ä¤Q¦¡¡uÆF¡v,$N¸[®ð¾®¯«,¤@Án¡u³Ü ~ ~ ~¡vªº¤@Án\nÜ       ,¤Q¤èÆF°Ê©b¦VªÅ¤¤,$N¬I®iµL¤W»´¥\,¸õ¨ì¤Q¤èÆF°Êªº®ÇÃä\n"NOR
        +HIC"Áô¨£¤Q¤èÆF°Ê³Q¹p«E¤¤,´²µo¥X«e©Ò¥¼¦³ªº¥ú¨~ + + + + +\n"NOR          +HIR"§A§â¤â«ü«ü¦V$N,¤Q¤èÆF°Ê¯e³t­¸¦æ,¤×¦p­µ³t®g©¹$Nªº¯Ý³¡\n"NOR
        +HIB"µ²ªG³y¦¨$N"+damage+"ÂIªº¶Ë®`¡I¡I¡I¡I\n"NOR
        ,victim);
        return;
        }
}


