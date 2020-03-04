inherit ROOM;

void create()
{
        set( "short", "地底神殿遺跡") ;
        set( "long", @LONG
青綠色的詭異花紋依舊刻滿四周的牆壁，除了花紋之外，還多了
一些複雜的圖形，從中看來，圖形中隱含了許多人形的描繪，看久了
之後人形好像動了起來，正在跳著奇怪的舞蹈。
LONG
);
        set("exits", ([ /* sizeof() == 1 */
                  "west" : __DIR__"room-24",
        ]));
        set("objects",([
                   __DIR__"../npc/cha_na" : 1,
                 ]) );
        set("light",1);
        set("no_recall","神殿內部的磁場遮蔽了所有的傳送力量。");
        set("no_clean_up", 0);
        setup();
}

