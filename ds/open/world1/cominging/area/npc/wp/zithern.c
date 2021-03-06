#include <ansi.h>
#include <weapon.h>
inherit HAMMER;

void create()
{
        set_name("古箏",({ "old zithern","zithern" }));
        set_weight(4300);

        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit","只");
                set("value",2000+random(1000));
                set("limit_str",10);
                set("long",
                        "一個在官府之中樂團所常使用的樂器，中國的彈撥樂器。外形為木制長方形音箱，\n"
                        "板面成弧狀。唐、宋時弦數增為十三弦，現已增至二十五根弦。\n");
        }
        init_hammer(27,TWO_HANDED);
        set("combat_msg", ({ //攻擊訊息 $N是自己 $n是對方 $l 是對方受攻部位 $w是武器名稱
                             // 宮商角徵羽
  "$N將手上的$w彈出商音，聲音往$n而去，似乎對$n有些影響。",
  "$N輕輕彈起' 春梅曲 '其中的音高震的$n有些頭痛。",
  "$N拿著$w不知覺當中，彈出了最精深的一首樂曲，$n似乎有些著迷，有些樂不思蜀。",
  "$N彈出高音"HIG"【"HIC"羽"HIG"】"NOR"，將$n耳朵簡直快受不了。",
  HIW"$N拿起$w，按下其中機關，射出許\多小箭射向$n的$l。"NOR,
}));
        setup();
}
