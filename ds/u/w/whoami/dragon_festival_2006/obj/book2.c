
#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIC"Â²©öª©ºÝ¤È­¹ÃÐ"NOR,({"cookery book","book"}) );
        set("long",@LONG

¥x¦¡¥Õºê¡G¦Ë¸­¡BºêÃ·¡BÄz¦Ì¡B½Õ¨ý®Æ¡B½Þ¦×¡B­»Û£¡BÂû³J

ºñ¨§Àn³Jºê¡G¦Ë¸­¡BºêÃ·¡BÄz¦Ì¡B½Õ¨ý®Æ¡Bºñ¨§¡Bªá¥Í¦Ì¡BÀn³J


³¯¥Ö¤û¦×ºê¡G¦Ë¸­¡BºêÃ·¡BÄz¦Ì¡B½Õ¨ý®Æ¡Bºñ¨§¡B¤û¦×¡B³¯¥Ö¡B½Þ¦×

¥|¤t´ÔÆQ¨§ºê¡G¦Ë¸­¡BºêÃ·¡BÄz¦Ì¡B½Õ¨ý®Æ¡B¬õ¨§¡B½Þ¦×¡Bªá´Ô

¦ÊªGºê¤l¡G¦Ë¸­¡BºêÃ·¡BÄz¦Ì¡B½Õ¨ý®Æ¡B¥V¥Ê±ø¡B®Ö®ç¤¯¡B«C±ö

³½­»²ü¸­ºê¡G¦Ë¸­¡BºêÃ·¡BÄz¦Ì¡B½Õ¨ý®Æ¡B½¼¦Ì¡BÅÚ½³°®¡B­»Û£¡B³½¦×¡B¤TÄ_¦Ì

°·±d¯Àºê¡G¦Ë¸­¡BºêÃ·¡BÄz¦Ì¡B½Õ¨ý®Æ¡Bªá¥Í¡B­»Û£¡B®ß¤l¡BÅÚ½³°®¡B¤TÄ_¦Ì¡B¯»¸­

¼sªFÄª°Âºê¡G¦Ë¸­¡BºêÃ·¡BÄz¦Ì¡B½Õ¨ý®Æ¡B¬õ¨§¡B®ß»T¡B´Çªd¡B½¬»T¡B¤TÄ_¦Ì

LONG
);
        set_weight(200);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("value",100);
                set("unit","¥»"); 
        }
        setup();
}
