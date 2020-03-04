//ºx§Â§Ò¡…eq 200.10.14 by Promise@DS
#include <armor.h>
#include <ansi.h>
inherit HANDS; 
void create()
{
        set_name(HIW"§—®œ§ß¡l"NOR,({"the wing of angel","wing","angel","the","of","t","w","o","a"}) );
        set("long",HIW"    ≥o¨O§@≠”≥y´¨©_ØS™∫§‚ÆM°A®∫§£™æ©˙™∫ß˜ΩË©M•W•Y§£•≠™∫•~™Ì°A
ßÛ¨≈„§F•¶™∫§£•≠§Z°A¶b®∫§ß§W¶∆µ€≤H≤H™∫ª»•’¶‚•˙®~°A¶≥µ€ßœ©ªØ‡
Æg≥z§@§¡∂¬∑t™∫•˙µÿ°A®∫¨X©M™∫•˙®~¶b§‚ÆM™∫™Ì≠±≤H≤H™∫¥≤µoµ€°A¶n
π≥¿HÆ…≥£•iØ‡∫∂∑¿°A¶˝µLΩ◊¨O¶b¶høKØP™∫§”∂ß©≥§U§@ºÀ¡Ÿ¨O•i•H≤M∑°
™∫¨›®Ï•¶™∫•˙Ω˜°A§£πL•O§H©_©«™∫¨O°A¨∞§∞ªÚ≥o§‚ÆM•u¶≥•™§‚™∫≥°§¿
°A¶”®S¶≥•k§‚™∫≥°§¿°C
\n"NOR);
        set_weight(16000);
        if ( clonep() )
                set_default_object(__FILE__);
         else {
         set("volume",2);
         set("material","silver");
         set("unit", "≠”" );
         set("no_sell",1); 
         set("no_give",1);
         set("no_auc",1);
         set("no_drop",1);         }
        set("armor_prop/armor", 1);
        set("wear_msg","
      [0;1m¢[1m®[1m¢[1mi[1m¢[1mh[1m¢[1mg[1m¢[1mf[1m¢[1me[1m¢[1md[1m¢[1me[1m¢[1mf[1m¢[1mg[1m¢[1m´[0m "HIG"∑Ì"NOR"$N"HIG"±N"HIW"§—®œ§ß¡l"HIG"Æ≥∞_
[0;1;32m [1m [1m [1m [1;37m¢[1m®[1;47m¢[1m´[1m¢[1mi[1m¢[1mi[1m¢[1m™[1m¢[1mh[1m¢[1mg[1m¢[1mf[1m¢[1me[1m¢[1md[1m¢[1m®[1;40m¢[1m©[1m [0m"HIW"§—®œ§ß¡l"HIG"™∫•˙®~∂V®”∂V¬`≤¥
[0;1;32m [1m [1;37m¢[1m®[1;47m¢[1m´[1m¢[1mi[1m¢[1m®[1m¢[1mi[1m¢[1mg[1m¢[1mf[1m¢[1me[1m¢[1md[1m¢[1mc[1m¢[1m®[1;40m¢[1m©[1;32m [1m [1m [0m"HIG"∑ÌßA¶A¶∏¨›≤M™∫Æ…≠‘
[0;1m¢[1m®[1;47m¢[1m´[1m¢[1mi[1m¢[1m®[1m¢[1m´[1;40m¢[1m™[1;47m¢[1mh[1m¢[1mg[1m¢[1me[1m¢[1mc[1m¢[1mi[1;40m¢[1m©[1;32m [1m [1m [1m [1m [0m"HIG"$N™∫•™§‚§w∏g§∆¶®§@§˘¶–¡l
[0;1m¢[1m™[1m¢[1mi[1m¢[1mi[1;47m¢[1m´[1;40m¢[1m™[1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m¢[1m™[1;32m [1m [1m [1m [1m [1m [1m [0m"HIG"®√¥≤µoµ€©M≠Ï®”§@ºÀ≤H≤H™∫•˙Ω˜\n"NOR);
     set("unequip_msg",HIG"∑Ì$N±N"HIW"§—®œ§ß¡l"HIG"≤Ê§UÆ…°A•™§‚™∫¶–¡l§∆¨∞¬I¬I•˙®~¥≤•h°A¶^¥_®Ï≠Ï¶≥™∫ºÀ§l°C\n"NOR);
        setup();
}

int query_autoload() { return 1; }

void init()
{
        if(!this_object()->query_light()) this_object()->start_light(1);
}

